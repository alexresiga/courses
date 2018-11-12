bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 1, 2, 3, 4
    len equ ($-a)/4
    format db "%d",10,13,0

; our code starts here
segment code use32 class=code
    start:
        mov ebx, 0
        mov ecx, len
        cmp ecx, 0
        je final
        bucla:
            mov eax, [a+ebx]
            push dword ecx ;pushad
            ;-------------
            push dword eax
            push dword format
            call [printf]
            add esp, 4*2
            ;----------
            pop dword ecx ;popad
            add ebx, 4
            dec ecx
            cmp ecx, 0
            jne bucla 
        
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
