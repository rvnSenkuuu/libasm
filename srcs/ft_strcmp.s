global ft_strcmp
section .text

ft_strcmp:
	xor rax, rax
	xor rcx, rcx

.loop:
	mov al, byte [rdi + rcx]
	mov bl, byte [rsi + rcx]
	cmp al, bl
	jne .sub_return
	test al, al
	je .return
	inc rcx
	jmp .loop

.sub_return:
	movzx rax, al
	sub rax, rbx
	ret

.return:
	xor rax, rax
	ret