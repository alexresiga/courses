 bits 32

global start        

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll
;Se da un sir de dublucuvinte. Sa se afiseze in fisier rangul octetului cel mai mic din dcuvantul respectiv. Daca ai 12345678h, 34567878h, 98h ;afiseaza : 1 1 4. Apoi sa se afiseze pe randul urmator suma acestor octeti.
segment data use32 class=data
    
    sir dd 12345678h, 34567878h, 98h
    len equ ($-sir)/4
    format db "%d ", 0
    min db 255
    poz dd 0
segment code use32 class=code
    start:
        
        xor ebx, ebx
        mov ebx, len
        
        altabucla:
        xor ecx, ecx
        mov ecx, 4
        mov esi, 0
        bucla:
            mov al, [sir+esi]
            cmp al, [min]
            ja not_min
            mov [min], al
            
            mov [poz], esi
            not_min:
            inc esi
        loop bucla
        
        push dword [poz]
        push dword format
        call [printf]
        
        dec ebx
        cmp ebx, 0
        ja altabucla
        
        
        
    
        ; exit(0)
        push    dword 0
        call    [exit]
