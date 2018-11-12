bits 32

global start        

extern exit, fopen, fclose, fread, fprintf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll
;
segment data use32 class=data
    nume db "prefiles.txt", 0
    mod_access db "r", 0
    descriptor dd -1
    len equ 100
    text times len db 0
    write_mode db "w", 0
    filename db "prepFilesWrite.txt", 0
    handler dd -1
    format db "%x",0

segment code use32 class=code
    start:
        ;fopen(nume, mod_access)
        push dword mod_access
        push dword nume
        call [fopen]
        add esp, 8
        
        cmp eax, 0
        je final
        mov [descriptor], eax
        ;---------------------
        push dword [descriptor]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        ;----------------------
        cld
        mov ecx, eax
        mov ebx, 0
        mov esi, text
        bucla:
            lodsb
            cmp al, 'a'
            je vowel
            cmp al, 'e'
            je vowel
            cmp al, 'i'
            je vowel
            cmp al, 'o'
            je vowel
            cmp al, 'u'
            je vowel
            jmp not_vowel
            vowel:
                inc ebx
            not_vowel:
            loop bucla
            pushad
            push dword ebx
            push dword format
            call [printf]
            add esp, 4*2
            popad
                
        
        
        ;----------------------
        push dword write_mode
        push dword filename
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        mov [handler], eax
        
        push dword ebx
        push dword format
        push dword [handler]
        call [fprintf]
        add esp, 8
        ;---------------------
        push dword [descriptor]
        call [fclose]
        add esp, 4
        
        push dword [handler]
        call [fclose]
        add esp, 4
        
        
        final:
        ; exit(0)
        push    dword 0
        call    [exit]
        