bits 32

global start        

extern exit, fread, fopen, scanf, fprintf, printf, fclose
import exit msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

;
segment data use32 class=data
    a dw 0FFh
    b db 2
    format db 'catul: %d, restul: %d',0
segment code use32 class=code
    start:
    xor eax, eax
        mov al, [a]
        imul byte [b]
        xor edx, edx
        xor eax, eax
        mov dx, 0
        mov ax, [a]
        mov bx, 0
        mov bl, [b]
        div bx
        push dword edx
        push dword eax
        push dword format
        call [printf]
        add esp, 4*3
        
        ; exit(0)
        push    dword 0
        call    [exit]
