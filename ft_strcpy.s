section.text:
	global _ft_strcpy

	_ft_strcpy:							; rsi = source / rdi = destination
		xor		rcx, rcx				; counter
		xor		rdx, rdx				; temp store (dl)
		xor		rax, rax
		cmp		rsi, 0x0				; Source != '\0'
		jz		finish
		cmp		rdi, 0x0
		jz		finish
		jmp		copy

	increment:
		inc		rcx						; increment counter

	copy:
		mov		dl, BYTE [rsi + rcx]	; Move into temp
		mov		BYTE [rdi + rcx], dl	; Move temp into destination
		cmp		dl, 0x0					; Did you reach the '\0'
		jnz		increment
	
	finish:
		mov		rax, rdi				; Copy to return register.
		ret
