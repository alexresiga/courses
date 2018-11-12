bits 32

global start        

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

;
segment data use32 class=data
    s1 dd 1, 2, 3, 4
    lenS1 equ ($-s1)/4
    s2 dd 5, 6, 7, 8
    lenS2 equ ($-s2)/4
    d times (lenS1+lenS2) dd 0
    format db "%d ",0

segment code use32 class=code
    start:
        mov ebx, 0
        mov ecx, lenS1
        cmp ecx, 0
        je final
        bucla:
            mov eax, [s1+ebx]
            mov [d+ebx],eax
            add ebx, 4
            dec ecx
            cmp ecx, 0
            jne bucla
         
        mov ebx, (lenS2-1)*4
        mov edx, 0
        mov ecx, lenS2
        cmp ecx, 0
        je final
        invers:
            mov eax, [s2+ebx]
            mov [d+lenS1*4+edx], eax
            add edx, 4
            sub ebx, 4
            dec ecx
            cmp ecx, 0
            jne invers
        mov ecx, lenS1+lenS2
        jecxz final
        mov esi, 0
        afis:
            mov eax, [d+esi]
            pushad
            push dword eax
            push dword format
            call [printf]
            add esp, 4*2
            popad
            add esi, 4
            loop afis 
        final:
        ; exit(0)
        push    dword 0
        call    [exit]
