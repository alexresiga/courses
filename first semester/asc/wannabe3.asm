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
    format_text db "%s", 0
    format_nr db "%d", 0
    format_char db "%s", 0
    desc_in dd -1
    desc_out dd -1
    read_mode db 'r', 0
    append_mode db 'a', 0
    file_out db 'output.txt', 0
    len equ 100
    text times (len+1) db 0
    file_in times (len+1) db 0
    mesaj db 's: ', 0
    s dd 0
    mesajN db 'n: ', 0
    n dd 0
    


segment code use32 class=code
    start:
        ;scanf(format, nume fisier)
        push dword file_in
        push dword format_text
        call [scanf]
        add esp, 4*2
         
        push dword mesaj
        push dword format_text
        call [printf]
        add esp, 4*2
        
        push dword s
        push dword format_char
        call [scanf]
        
        push dword mesajN
        push dword format_text
        call [printf]
        add esp, 4*2
        
        push dword n
        push dword format_nr
        call [scanf]
        add esp, 4*2
        
        ;fopen(nume, mod_acces)
        push dword read_mode
        push dword file_in
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je close
        mov [desc_in], eax
        
        
        ;fopen(nume, mod_acces)
        push dword append_mode
        push dword file_out
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je close
        mov [desc_out], eax
        
        ;fread(text, 1, len, desc_in)
        push dword [desc_in]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ;fprintf(handler, format, mesaj)
        push dword text
        push dword format_text
        push dword [desc_out]
        call [fprintf]
        add esp, 4*3
        
        
        close:
        push dword [desc_in]
        call [fclose]
        add esp, 4
        
        push dword [desc_out]
        call [fclose]
        add esp, 4
        ; exit(0)
        push    dword 0
        call    [exit]

        