global ft_atoi_base
; int	ft_atoi_base(char *str, char *base);
; rax	ft_atoi_base(rdi, rsi);

section .text
check_base:
	push rbx
	push rdx
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
	pop rdx
	pop rbx
	xor rax, rax
	ret

.check_base_ret:
	pop rdx
	pop rbx
	mov rax, rcx
	ret

ft_atoi_base:
	mov r11, rdi
	mov rdi, rsi
	call check_base
	cmp rax, 2
	jl .ft_atoi_base_ret_zero
	mov rdi, r11

	mov r8, rax ; base length given by check_base function
	xor rcx, rcx ; index counter register
	xor r10, r10 ; result register moved to rax at the end
	mov rbx, 1 ; sign register

.skip_space:
	mov al, [rdi + rcx]
	cmp al, 9
	je .inc_skip_space
	cmp al, 10
	je .inc_skip_space
	cmp al, 11
	je .inc_skip_space
	cmp al, 12
	je .inc_skip_space
	cmp al, 13
	je .inc_skip_space
	cmp al, 32
	je .inc_skip_space
	jmp .check_sign

.inc_skip_space:
	inc rcx
	jmp .skip_space

.check_sign:
	mov al, [rdi + rcx]
	cmp al, 43
	je .sign_plus
	cmp al, 45
	je .sign_minus
	jmp .main_loop

.sign_plus:
	inc rcx
	jmp .check_sign

.sign_minus:
	inc rcx
	neg rbx
	jmp .check_sign

.main_loop:
	cmp byte [rdi + rcx], 0
	je .ft_atoi_base_ret

.in_base:
	xor r9, r9
	mov al, [rdi + rcx]

.in_base_loop:
	cmp byte [rsi + r9], 0
	je .ft_atoi_base_ret
	mov dl, [rsi + r9]
	cmp al, dl
	je .compute_res
	inc r9
	jmp .in_base_loop

.compute_res:
	imul r10, r8
	add r10, r9
	inc rcx
	jmp .main_loop

.ft_atoi_base_ret_zero:
	xor rax, rax
	ret

.ft_atoi_base_ret:
	imul r10, rbx
	mov rax, r10
	ret