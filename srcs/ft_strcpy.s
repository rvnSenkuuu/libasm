; char	*ft_strcpy(char *dest, const char *src)
; {
; 	int	i = 0;
; 	while (src[i]) {
; 		dest[i] = src[i];
; 		i++;
; 	}
; 	dest[i] = '\0';
; 	return dest;
; }

global ft_strcpy
section .text

ft_strcpy:
	xor rax, rax
	xor rcx, rcx

.loop:
	mov al, byte [rsi + rcx]
	mov byte [rdi + rcx], al
	cmp al, 0
	je .return
	inc rcx
	jmp .loop

.return:
	mov rdi, 0
	mov rax, rdi
	ret