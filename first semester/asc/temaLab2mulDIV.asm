bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a,b,c - byte, d - word
    a db 6
    b db 2
    c db 1
    d dw 9

; our code starts here
segment code use32 class=code
    start:
        ; [d-2*(a-b)+b*c]/2 
        mov al, [a]  ;AL = a
        sub al, [b]  ;AL = a - b 
        mov ah, 2    ;Ah = 2
        mul ah       ;AX = AL * AH = 2*(a-b) 
        mov bx, ax   ;BX = 2 * (a - b)
        mov al, [b]  ;AL = b
        mul byte [c] ;AX = b * c
        mov cx, ax
        mov ax, [d]
        sub ax, bx
        add ax, cx
        mov bl, 2
        div bl ; AL= quotient AH= remainder
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
