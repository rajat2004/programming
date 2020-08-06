; NASM Assembly Language file
; Compilation: nasm -f elf64 matrix.asm && ld matrix.o && ./a.out
; Multiplies 2 matrices and prints the resulting matrix
; Input: m n p q (Size of both matrices)
; Output 0 if multiplication not possible
; Else, input the matrix elements and print output

%include "io.inc"
section .data
	newline_char: db 10
	whitespace: db 32
	store_int: times 8 db 0
	null_terminate: db 0

section .bss
	matrix1: resq 100
	matrix2: resq 100

section .text
global _start


matrix_mul:
	push rax
	push rcx
	push rdx
	push rbx
	push rsp
	push rbp
	push rsi
	push rdi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	; rdi: Address of final matrix
	; rsi: Add of matrix 1
	; rdx: Address of matrix 2
	; r8: (m), No. of rows of matrix 1
	; r9: (q), No. of cols of matrix 2
	; r10: (n)=(p), No. of cols of matrix 1 = No. of rows of matrix 2
	; r11: (i) 0-m
	; r12: (j) 0-q
	; r13: (k) 0-p

	; for(i=0; i<m; i++){
	; 	for(j=0; j<q; j++){
	; 		for(k=0; k<p; k++)
	; 			matrix3[i][j] += matrix1[i][k]*matrix2[k][j];
	; 	}
	; }

	xor r11, r11			;Initialize i

	.loop1:
		cmp r11, r8			;Check if i<m
		je .finish

		xor r12, r12		;Initialize j
		jmp .loop2


		.loop2:
			cmp r12, r9			;Check if j<q
			je .end_loop2

			xor r13, r13		;Initialize k
			xor rax, rax
			jmp .loop3


			.loop3:
				cmp r13, r10		;Check if k<p
				je .end_loop3

				; rbx will contain the final offset from the respective matrix
				mov rbx, r13
				imul rbx, r9						; k*q
				add rbx, r12						; k*q + j
				mov r14, [matrix2 + rbx*8]			; matrix2[k][j]

				mov rbx, r11
				imul rbx, r10						; i*n
				add rbx, r13						; i*n + k
				mov r15, [matrix1 + rbx*8]			; matrix1[i][k]

				imul r15, r14						;matrix1[i][k]*matrix2[k][j]

				add rax, r15						; matrix3[i][j] +=

				inc r13								;Increment k
				jmp .loop3


			.end_loop3:
				push r15
				push r14
				push r13
				push r12
				push r11
				push r10
				push r9
				push r8
				push rax
				push rdi
				push rdx
				push rsi
				push rcx

				mov rdi, rax
				call print_int

				mov rdi, whitespace
				call print_char

				pop rcx
				pop rsi
				pop rdx
				pop rdi
				pop rax
				pop r8
				pop r9
				pop r10
				pop r11
				pop r12
				pop r13
				pop r14
				pop r15

				inc r12				;Increment j
				xor r13, r13		;Initialize k
				xor rax, rax
				jmp .loop2


		.end_loop2:
			push r15
			push r14
			push r13
			push r12
			push r11
			push r10
			push r9
			push r8
			push rax
			push rdi
			push rdx
			push rsi
			push rcx

			call print_newline

			pop rcx
			pop rsi
			pop rdx
			pop rdi
			pop rax
			pop r8
			pop r9
			pop r10
			pop r11
			pop r12
			pop r13
			pop r14
			pop r15
			inc r11				;Increment i
			xor r12, r12		;Initialize j for next iteration
			jmp .loop1

	.finish:
		pop r15
		pop r14
		pop r13
		pop r12
		pop r11
		pop r10
		pop r9
		pop r8
		pop rdi
		pop rsi
		pop rbp
		pop rsp
		pop rbx
		pop rdx
		pop rcx
		pop rax

		ret

read_int:
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	mov rdi,store_int;
	mov rsi,7
	call read_word

	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8

	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	mov rdi,rax
	call parse_int

	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8

	ret

_start:
	call read_int
	mov r8 ,rax				; Store m

	call read_int
	mov r9, rax				; Store n

	call read_int
	mov r10, rax			; Store p

	call read_int
	mov r11, rax			; Store q

	cmp r9, r10
	jne .error

	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	mov r12, r8
	imul r12, r9
	xor r13, r13

	.loop1:
		cmp r13, r12		; m*n elements
		je .continue1

		call read_int

		mov [matrix1 + r13*8], rax

		inc r13
		jmp .loop1

	.continue1:
		pop r15
		pop r14
		pop r13
		pop r12
		pop r11
		pop r10
		pop r9
		pop r8

		push r8
		push r9
		push r10
		push r11
		push r12
		push r13
		push r14
		push r15

		mov r12, r10
		imul r12, r11
		xor r13, r13

	.loop2:
		cmp r13, r12	; p*q elements
		je .continue2

		call read_int

		mov [matrix2 + r13*8], rax

		inc r13
		jmp .loop2

	.continue2:
		pop r15
		pop r14
		pop r13
		pop r12
		pop r11
		pop r10
		pop r9
		pop r8

		mov r9, r11
		mov rsi, matrix1
		mov rdx, matrix2
		call matrix_mul

		call exit

	.error:
		mov rdi, 0
		call print_uint
		call exit
