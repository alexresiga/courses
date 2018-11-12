bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
;(a+b) - ( c +d) = ? ;a,b,c,d:words 
segment data use32 class=data
    a dw 16
    b dw 0x10
    c dw 0x20
    d dw 1
    

; our code starts here
segment code use32 class=code
    start:
        ; a+b
            mov ax, [a]
            add ax, [b] ;ax=a+b
            
        ;c+d
            mov bx, [c]
            add bx, [d] ; bx= c+d
        ; (a+b) - (c+d)
            sub ax,bx ;ax = ax - bx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
