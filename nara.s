;nasm -f macho64 nara.s && gcc nara.o -o nara;
section .data
	msg db "Hello, Nara!",0x0a,"Nara nara shika shika inaina",0x0a
	len equ $ - msg

section .text
	global _main
_main:
	; SYSCALL: write(1, msg, len);
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, msg
	mov rdx, len
	syscall

	; SYSCALL: exit(0)
	mov rax, 0x2000001
	mov rdi, 0
	syscall

