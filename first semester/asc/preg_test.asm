bits 32

global start        

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll
;
segment data use32 class=data
  sir db 'ac',0

segment code use32 class=code
    start:
        xor eax, eax
        mov esi, 0
        mov al, sir
        inc al
        mov bl, al
        ; exit(0)
        push    dword 0
        call    [exit]
