bits 32

global start        

extern exit, fopen, fclose, fprintf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
;
segment data use32 class=data
    nume db 'ana.txt', 0
    mod_acces db 'w', 0
    descriptor dd 0
    text db "ana are mere", 0
; 1)deschidere -numele
; 2)operatii- descriptor obtinut la deschidere
; 3)inchidere- -||-

segment code use32 class=code
    start:
        ; open a file called ana.txt
        ; fopen(nume, mod_acces)
        push dword mod_acces
        push dword nume
        call [fopen]
        add esp, 4*2
        ;eax = descriptor fisier sau 0 in caz de eroare
        cmp eax, 0
        je final
        mov [descriptor], eax
        ;------------------------------
        ;operatii cu fisier
        ; write ana are mere in file
        ; fprintf(descriptor, "ana are mere"
        push dword text
        push dword [descriptor]
        call [fprintf]
        add esp, 4*2
        ;------------------------------
        ;fclose(descriptor)
        push dword [descriptor]
        call [fclose]
        add esp, 4
        
        
        
        final:
        ; exit(0)
        push    dword 0
        call    [exit]
