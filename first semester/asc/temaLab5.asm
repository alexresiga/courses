bits 32
global start        

extern exit, scanf               
import exit msvcrt.dll
import scanf msvcrt.dll

;Sa se citeasca de la tastatura doua numere (in baza 10) si sa se calculeze produsul lor. Rezultatul inmultirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date). 
segment data use32 class=data
    a dd 0
    b dd 0
    result dq 0
    format db "%d", 0
    citire db "%d", 0

segment code use32 class=code
    start:
        push dword a
        push dword format
        call [scanf]  ; reading a
        add esp, 4*2  ; clearing stack
        
        push dword b
        push dword citire
        call [scanf] ; reading b
        add esp, 4*2 ; clearing stack
        
        mov eax, [a] ; EAX = a
        imul dword [b] ; EDX:EAX = a*b
        mov [result], eax
        mov [result+4], edx ;moving the result in the quadword result 
         
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
