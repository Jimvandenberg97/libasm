section.text:
    global     _ft_write

_ft_write:
            mov     rax, 0x2000004      ; System call to write
            syscall
            jc      return_error        ; Jump if write fails
            jmp     return

return_error:
            mov     rax, -1             ; Move -1 to return value
            ret

return:
            ret