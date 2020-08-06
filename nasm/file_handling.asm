; These macrodefinitions are copied from linux sources
; Linux is written in C, so the definitions looked a bit
; different there.
; We could have just looked up their values and use
; them directly in right places
; However it would have made the code much less legible

%define O_RDONLY 0
%define O_CREAT 0x40
%define O_RDWR 2
%define PROT_READ 0x1
%define PROT_WRITE 0x2
%define MAP_PRIVATE 0x2
%define MAP_SHARED 0x1

section .data
	ifname: db 'input.txt', 0
	ofname: db 'output.txt', 0
	
section .text
global _start

string_copy:
	;push rdi				;rdi stores the address of the first string
							;rdx stores the length of the buffer
							;rsi stores buffer address
	call string_length 		;Find length of first string
	cmp rax, rdx			;Check if string can fit in buffer 
	jge .error

	push rsi				;Store address of destination
	mov r9, 0

	.loop1:
		test rax, rax
		jz .end

		mov r13b, byte[rdi + r9]	;Copy character
		mov byte[rsi + r9], r13b	
		inc r9						;Increment address
		dec rax
		jmp .loop1

	.end:
		mov byte[rsi + r9], 0		; Null terminate
		pop rax						; Return address of destination string
		ret

	.error:
		xor rax, rax				;Return 0
		ret


string_length:
    xor rax, rax
	.loop:
	    cmp byte [rdi+rax], 0
	    je .end
	    inc rax
	    jmp .loop
	.end:
    ret


_start:
; call open
	mov rax, 2
	mov rdi, ifname
	mov rsi, O_RDONLY     ; Open file read only
	mov rdx, 0            ; We are not creating a file
	                      ; so this argument has no meaning
	syscall

; mmap
	mov r8, rax           ;rax holds opened file descriptor
	                      ;it is the fourth argument of mmap
	mov rax, 9            ;mmap number
	mov rdi, 0            ;operating system will choose mapping destination
	mov rsi, 4096         ;page size
	mov rdx, PROT_READ    ;new memory region will be marked read only
	mov r10, MAP_PRIVATE  ;pages will not be shared
	mov r9, 0				; offset inside test.txt
	syscall					; now rax will point to mapped location

	mov r12, rax		  	; r12 now contains address of input file
	

; Create output.txt

	mov rax, 2
	mov rdi, ofname
	mov rsi, O_CREAT
	mov rdx, 0x1c0
	syscall

; Now rax contains the file descriptor
; Close the file

	mov rdi, rax
	mov rax, 3
	syscall
	

; call Open for write file in READ Write mode
	mov rax, 2
	mov rdi, ofname
	mov rsi, O_RDWR
	mov rdx, 0
	syscall
	
	mov r11, rax			; r11 contains file descriptor for output file
	
; FILE TRUNCATE
	push r11
	push r12

; First, find size of input file using string length
	mov rdi, r12
	call string_length

	; rax contains string_length
	pop r12
	pop r11

	push r11

; ftruncate sys call
	mov rsi, rax			; Size of input file
	mov rdi, r11			; Fd of output file
	mov rax, 77				; Syscall
	syscall

; Map output file in PROT_WRITE, MAP_SHARED
	pop r11

	mov rax, 9
	mov r8, r11				; Fd of output file
	mov rdi, 0				; OS chooses mapping destination
	mov rsi, 4096			; Page size 
	mov rdx, PROT_WRITE
	mov r10, MAP_SHARED
	mov r9, 0				; Offset
	syscall

; rax now contains address of output.txt

	mov r11, rax

	; r11 - Address of output file
	; r12 - Address of input file
; STRING COPY
	push r12
	push r11

	mov rdi, r12			; Address of input string
	mov rsi, r11			; Address of output file
	mov rdx, 4096			; Maximum size
	call string_copy


	pop r11
	pop r12

	; UNMAP

	mov rax, 11
	mov rdi, r12
	mov rsi, 4096
	syscall

	mov rax, 11
	mov rdi, r11
	mov rsi, 4096
	syscall

	mov rax, 60           ; use exit system call to shut down correctly
	xor rdi, rdi
	syscall