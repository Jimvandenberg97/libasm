section.text:
	global _ft_strcmp

    _ft_strcmp:
            mov     rax, 0x0                    ; Zero out return register                             rdi = s1   rsi = s2
            jmp     compare                     ;                                                      al = LSB rax     bl = LSB rbx

    compare:
            mov     al, BYTE [rdi]              ; Move least significant byte (the char) into al
            mov     bl, BYTE [rsi]              ; Move least significant byte (the char) into bl 
            cmp     al, 0x0                     ; Do we encounter a NULL character
            je      exit
            cmp     bl, 0x0
            je      exit
            cmp     al, bl                      ; Compare string 1 and 2
            jne     exit                        ; If they are not the same jump to exit
            inc     rdi                         ; Increment to the next index of both strings
            inc     rsi
            jmp     compare                     ; Go to the top of compare function

    exit:
            movzx   rax, al                     ; Copy al (LSB) of rax into rax, filling the other bits with 0
            movzx   rbx, bl
            sub     rax, rbx                    ; Save the difference of rax and rbx in rax and return
            ret