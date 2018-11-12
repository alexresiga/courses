bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
        mov al, 7
        mov bl, 8
        cmp al, bl
        je done
        mov ecx, 0
        jmp aici
        done:
            mov ecx, 1
            
        aici: 
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        ; char[] a = "ana are mere" -> a db "ana are mere"
        ;->"a", "n", ... 
        ; int[] b = {1, 2, 3} -> b dd 1, 2, 3 
        ;-> 01 00 00 00 | 02 00 00 00 | 03 00 00 00
        ;___________________
        ;data segment ...
        ;a dd 2, 3, 4
        ;c equ ($-a)/4  numar de elemnte din sirul a    ;;definire de constante equ <=> #define 
        ; b dw 1, 4, 6, 7
        ;len_b equ ($-b)/2
        ;___________________
        ;JMP label
        ;i1
        ;i2
        ;i3
        ;i4
        ;label:
        ;     i7
        ;     jmp label 
        ; ___________________
        ; if (cond) then
        ;i1
        ; else
        ;i2
        ;___________________
        ; if (a<b)
        ;CMP opd, ops