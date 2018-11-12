bits 32

global start        

extern exit, scanf, fopen, fclose, fread, fprintf
import exit msvcrt.dll
import scanf msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
;
segment data use32 class=data
    format db '%s', 0
    format_nr db "%d", 0
    x dd 0
    desc dd -1
    len equ 100
    buffer resb len
    nume resb len
    nr dd 0
    read_mode db 'r',0
    write_mode db 'w', 0
    fileOut db 'output22.txt',0
    desc_out dd -1
segment code use32 class=code
    start:

        push dword nume
        push dword format
        call[scanf]
        
        ;fopen(nume, mod acces)
        push dword read_mode
        push dword nume
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je close
        mov [desc], eax
        
        bucla:
            ;fread(buffer, 1, len, desc)
            push dword [desc]
            push dword len
            push dword 1 
            push dword buffer
            call [fread]
            add esp, 4*4
            
            cmp eax, 0
            jz afara
            add [nr], eax
            jmp bucla
            afara:
        ;fopen(nume, mod_access)
        push dword write_mode
        push dword fileOut
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je close
        
        mov [desc_out], eax
        
        push dword [nr]
        push dword format_nr
        push dword [desc_out]
        call [fprintf]
        add esp, 4*3
            
            
        close:
        ;fclose(desc)
        push dword [desc]
        call [fclose]
        add esp, 4
        
        push dword [desc_out]
        call [fclose]
        add esp, 4
    
        ; exit(0)
        push    dword 0
        call    [exit]
