bits 32

global start        

extern exit, fopen, fprintf, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
;
segment data use32 class=data
    nume db 'data.txt', 0
    mod_access db 'w', 0
    descriptor dd 0
    text db "a??adadas[]0dsa923][/23.2d",0
    len equ $-text-1
    sir db ",./<>?:;[]\{}|!@#$%^&*()-=+_", 0
    dest times len db 0
   
segment code use32 class=code
    start:
        ;open the file 'data.txt'
        push dword mod_access
        push dword nume
        call [fopen]
        add esp, 8
        ;eax = file descriptor or 0
        cmp eax, 0
        je final
        mov [descriptor], eax
        ;--------------------
        
        xor ecx, ecx
        mov ecx, len
        cld
        mov esi, 0 ;contpr text
        mov edi, 0 ;contor sir
        mov ebx, 0 ;contor dest
        jecxz final
        b:
        mov al, [text+esi] ; al = o litera din text
        mov edi,0
        altb:
        mov dh, [sir+edi]
        mov dl, al
        xor dl, dh
        jnz fara_replace ; if al is a special character we replace it with X
        mov [dest+ebx], byte 'X'
        inc ebx
        jmp afara
        fara_replace:
        inc edi
        cmp dh, 0 ;check to see if there are characters left in SIR
        jnz altb
        mov [dest+ebx], al
        inc ebx
        afara:
        inc esi
        loop b
   
        
        mov eax, dest
        push dword eax
        push dword [descriptor]
        call [fprintf]
        add esp, 4*2 
        ;---------------------
        
        push dword [descriptor]
        call [fclose]
        add esp, 4
        final:
        ; exit(0)
        push    dword 0
        call    [exit]
