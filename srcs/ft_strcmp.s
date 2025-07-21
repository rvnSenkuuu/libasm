global ft_strcmp

section .text
ft_strcmp:
	xor rax, rax
	xor rcx, rcx

.loop:
	mov al, byte [rdi + rcx] ;store the character at rdi[rcx] into al register
	mov bl, byte [rsi + rcx]
	cmp al, bl ;compare both character
	jne .sub_return ;if there a not equal to 0 go to .sub_return label
	test al, al ;check if we reach the end of s1 go to .return label
	je .return
	inc rcx
	jmp .loop

.sub_return:
	movzx rax, al ;extend the register al to rax with zero extended the other bits
	sub rax, rbx ;sub both character equal to return s1[i] - s2[i]
	ret

.return:
	xor rax, rax ;set rax to 0
	ret