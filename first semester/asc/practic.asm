bits 32

global start        

extern exit, scanf, fprintf, fopen, fclose, fread, printf, socket
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
import socket msvcrt.dll
;
segment data use32 class=data
    mod_access db "a",0
    handler dd -1
    nume resb 30
    format db "%s",0
    format_char db "%c", 0
    format2 db "%d", 0
    read_mode db "r", 0
    len equ 100
    text times len db 0
    desc dd -1
    dest db 'output.txt',0
    mesaj db 'Filename: ', 0
    write_mode db "w",0

segment code use32 class=code
    start:
       
        push dword mesaj
        push dword format
        call [printf]
        add esp, 4*2
        
        ;scanf(format, nume)
        push dword nume
        push dword format
        call [scanf]
        add esp, 4*2
        ;-------------------- CITIM NUME FISIER
        ;fopen(nume, readmode)
        push dword read_mode
        push dword nume
        call [fopen]
        add esp, 8
        ;--------------------DESCHIS PENTRU CITIRE
        cmp eax, 0
        je final
        mov [desc], eax
        
        push dword write_mode
        push dword dest
        call [fopen]
        add esp, 4*2
        
        
        ;fopen(nume, mode)
        push dword mod_access
        push dword dest
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je final
        mov [handler], eax
        
        
        bucla:
        ;fread(text, 1, len, desc)
        push dword [desc]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        cmp eax, 0
        jz final
        ;----------------------------- 
        mov esi, text
        mov ecx, eax
        cld
        repeta:
        mov eax, 0
        lodsb
        push ecx
        cmp al, '0'
        jb not_cifra
        cmp al, '9'
        ja not_cifra
        
        push dword eax
        push dword format2
        push dword [handler]
        call [fprintf]
        add esp, 4*3
        
        jmp final_loop
        not_cifra:
        ;fprintf(desc, format, mesaj)
        push dword eax
        push dword format_char
        push dword [handler]
        call [fprintf]
        add esp, 4*3
        final_loop:
        pop ecx
        loop repeta
        jmp bucla
        ;------------------------
        
        push dword [handler]
        call [fclose]
        add esp, 4
        ;fclose(desc)
        push dword [desc]
        call [fclose]
        add esp, 4
        final:
        ; exit(0)
        push    dword 0
        call    [exit]
