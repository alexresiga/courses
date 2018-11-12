bits 32

global start        

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

;s1, s2; s3 s1 + rev(s2)
segment data use32 class=data
    s1 dd 0xAB, 0xCD, 0xFF
    l1 equ ($-s1)/4
    s2 dd 0x12, 0x34
    l2 equ ($-s2)/4
    s3 times (l1+l2) dd 0
    format db "%x, ", 0

segment code use32 class=code
    start:
        mov ecx, l1
        jecxz step2
        mov esi, 0
        bucla:
            mov eax, [s1+esi]
            mov [s3+esi], eax
            add esi, 4
            loop bucla
        step2:
            mov ecx, l2
            jecxz step3
            mov edi, (l2-1)*4
            b2:
                mov eax, [s2+edi]
                mov [s3+esi], eax
                sub edi, 4
                add esi, 4
                loop b2
        step3:
            mov ecx, l1+l2
            jecxz final
            mov esi, 0
            b3:
                mov eax, [s3+esi]
                pushad
                push dword eax
                push dword format
                call [printf]
                add esp, 4*2
                popad
                add esi, 4
                loop b3 
        final:
    
        ; exit(0)
        push    dword 0
        call    [exit]
