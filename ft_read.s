section.text:
    global     _ft_read

_ft_read:
            mov     rax, 0x2000003      ; System call to read
            syscall
            jc      return_error        ; Jump if read fails
            jmp     return

return_error:
            mov     rax, -1             ; Move -1 to the return value
            ret

return:
            ret