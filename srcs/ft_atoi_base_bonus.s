global ft_atoi_base
; int	ft_atoi_base(char *str, char *base);
; rax	ft_atoi_base(rdi, rsi);

section .text
check_base:
	xor rcx, rcx

.outer_loop:
	mov al, byte [rdi + rcx]
	test al, al
	je .check_base_ret
	cmp al, 43
	je .check_base_ret_zero
	cmp al, 45
	je .check_base_ret_zero
	cmp al, 9
	je .check_base_ret_zero
	cmp al, 10
	je .check_base_ret_zero
	cmp al, 11
	je .check_base_ret_zero
	cmp al, 12
	je .check_base_ret_zero
	cmp al, 13
	je .check_base_ret_zero
	cmp al, 32
	je .check_base_ret_zero

	mov bl, al
	mov rdx, rcx
	inc rdx

.inner_loop:
	mov al, [rdi + rdx]
	test al, al
	je .inner_loop_end
	cmp al, bl
	je .check_base_ret_zero
	inc rdx
	jmp .inner_loop

.inner_loop_end:
	inc rcx
	jmp .outer_loop

.check_base_ret_zero:
	xor rax, rax
	ret

.check_base_ret:
	mov rax, rcx
	ret

ft_atoi_base:
	push rdi

	mov rdi, rsi
	call check_base
	cmp rax, 2
	jl .ft_atoi_base_ret_zero
	jmp .ft_atoi_base_ret

.ft_atoi_base_ret_zero:
	pop rdi
	xor rax, rax
	ret

.ft_atoi_base_ret:
	pop rdi
	ret