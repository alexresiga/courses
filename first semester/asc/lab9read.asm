bits 32

global start        

extern exit, fopen, fclose, fread
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
;where do we read from ? descriptor fisiser
;what do we read? bytes
;how much do we read? 
;where do we write what we read - un sir de caractere
;fread(str, size, count, descriptor)
segment data use32 class=data
    nume db 'ana.txt' , 0
    mod_acces db 'r', 0
    descr dd 0
    len equ 100
    text times len db 0

segment code use32 class=code
    start:
        ; fopen(nume, mod_acces)
        push dword mod_acces
        push dword nume
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        mov [descr], eax
        ;fread(text, 1, len, descr)
        push dword [descr]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ; eax - nr de caractere citite
        
        ;fclose(descr)
        push dword [descr]
        call [fclose]
        add esp, 4
        
    final:
        ; exit(0)
        push    dword 0
        call    [exit]
