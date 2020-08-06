print_newline:
	mov rdi, newline_char
	call print_char
	ret


print_char:
	mov rsi, rdi			;Address of string to output
	mov rax, 1				;System call for write
	mov rdi, 1				;File handle 1: Stdout
	mov rdx, 1				;No. of bytes to print
	syscall
	ret

print_uint:
	mov rax, rdi		
	mov r10, 10				;Stores divisor
	mov rdx, 0				;Set RDX to 0
	mov r12, 0				;Counter for number of digits

	.loop1:
		xor rdx, rdx 		;Set rdx to 0
		div r10				;Value in RAX divided by 10
		push rdx 			;Push RDX to stack
		add r12, 1			;Increment counter
		cmp rax, 0
		jnz .loop1

	.loop2:
		cmp r12, 0
		jz .loopend

		pop r15 			;Pop each digit to rsi
		mov rax, 1			;System call for write
		mov rdi, 1			;File handle 1: Stdout
		mov rdx, 1			;No. of bytes to print
		add r15, 48 		;Convert digit to ASCII value

		mov [val], r15
		mov rsi, val
		syscall

		sub r12, 1			;Decrement counter
		jmp .loop2

	.loopend:
		ret

print_int:
	cmp rdi, 0				;Compare int with 0
	jl .signed				;If int<0, convert to positive and print 

	call print_uint 		;Print positive integer
	ret

	.signed:
		xor r9, r9			;Make r9 0
		sub r9, rdi			;Subtract rdi form 0 and store in r9
		mov rdi, neg_sign		;Print -
		call print_char
		
		mov rdi, r9			;Restore integer
		call print_uint 	;Print positive integer
		ret

read_char:
	mov rax, 0				;System call for read
	mov rdi, 0				;File handle 0: Stdin
	mov rdx, 1				;No. of bytes to read_char
	mov rsi, rchar_store 	;Address of recieved char
	syscall
	mov rax, rsi
	ret

parse_uint:
	xor rax, rax				;Make rax 0, rax stores the integer
	xor rdx, rdx				;Make rdx 0, rdx stores count of characters

	.loop:
		cmp byte [rdi+rdx], 0	;Compare each character to 0
		je .end					;If reach end, exit loop

		movzx r9, byte [rdi+rdx]	;Move character to r9
		sub r9, 48					;Convert ASCII to decimal integer
		imul rax, 10				;rax = rax*10 + r9
		add rax, r9
		add rdx, 1					;Increment address
		jmp .loop

	.end:
		ret

parse_int:
	cmp byte [rdi], '-'		;Check if negative sign is present or not
	je .signed				;If yes, go to signed

	call parse_uint
	ret

	.signed:
		add rdi, 1			;Increment current address
		call parse_uint
		add rdx, 1			;Increment character count to include '-' sign
		;Negate value stored in rax
		mov r9, rax
		xor rax, rax;
		sub rax, r9
		ret

; 	buffer address: rdi
;	buffer size: rsi
;	Output: buffer address in rax if successful else 0
read_word:
	mov r12, rdi			;Save buffer address
	mov r9, rsi				;Store buffer size
	mov rsi, rdi			;Move buffer address in order to save characters read from stdin				;
	xor r10, r10			;Stores no. of characters read successfully

	.loop:
		cmp r10, r9				;Compare count of characters
		je .error				;If equal charcters read, terminate
		mov rax, 0				;System call for read
		mov rdi, 0				;File handle 0: Stdin
		mov rdx, 1				;No. of bytes to read_char 
		syscall
		cmp byte[rsi], 32		;Check whitespace
		je .end
		cmp byte[rsi], 10		;Check newline
		je .end
		inc rsi					;Icrement address
		inc r10
		jmp .loop

	.end:
		mov byte[rsi], 0			;Null Terminate
		mov rax, r12				;Restore buffer address and return
		ret

	.error:
		mov rax, 0				;Return 0
		ret
		

exit:
	mov rax, 60				; system call for exit					exit() system call number
	xor rdi, rdi			; exit code 0							first parameter -- exit status
	syscall					; invoke operating system to exit.
