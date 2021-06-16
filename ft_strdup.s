section.text:
	global  _ft_strdup
	extern	_ft_strlen
	extern	_malloc
	extern	_ft_strcpy

_ft_strdup:
	xor		rax, rax				; Empty rax
	cmp		rdi, 0x0				; Null check
	jz		return					; If null, yeet out

	call	_ft_strlen				; Get stringlength of input
	inc		rax						; +1 for nullbyte on end of string

	push	rdi						; Push src ptr on the stack
	mov		rdi, rax				; Set strlen as param for malloc
    push    rbp						; Push current frame pointer to stack
	mov     rbp, rsp				; Stack pointer in frame pointer
	and		rsp, -0x10				; Trim for stack alignment
	call	_malloc					; Call malloc
    mov     rsp, rbp				; Revert Frame pointer
    pop     rbp						; Pop frame pointer from stack
	pop		rdi						; Pop string pointer from stack

	jz		return					; Check malloc
	mov		rsi, rdi				; Set strcpy dest param
	mov		rdi, rax				; Set strcpy src param
    call	_ft_strcpy				; Call strcpy

return:
	ret								; Directly return value of strcpy