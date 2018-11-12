bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
; (a * b) / (c+d);a, b, c, d : bytes
segment data use32 class=data
    a db 0x10
    b db 7
    c db 5
    d db 4

; our code starts here
segment code use32 class=code
    start:
        ;a * b 
        mov al, [a]
        mul BYTE [b] ;AX = a * b
        
        ;c+d
        mov bl, [c]
        add bl, [d] ;bl = c + d
        
        div bl
        ; al = quotient ah= remainder
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
