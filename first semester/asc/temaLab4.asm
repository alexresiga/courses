bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; Se dau cuvintele A si B. Sa se obtina dublucuvantul C:
    ;bitii 0-4 ai lui C coincid cu bitii 11-15 ai lui A
    ;bitii 5-11 ai lui C au valoarea 1
    ;bitii 12-15 ai lui C coincid cu bitii 8-11 ai lui B
    ;bitii 16-31 ai lui C coincid cu bitii lui A

segment data use32 class=data
   a dw 0111011101010111b
   b dw 1001101110111110b
   c dd 0
; our code starts here
segment code use32 class=code
    start:
        mov ebx, 0 ; here we compute C 
        mov eax, 0 
        mov ax, [a] ; AX = a 
        and ax, 1111100000000000b ; isolating bits 11-15 of A
        ror ax, 11 ; moving them to positions 0-4
        or bx, ax ; bitii 0-4 ai lui C coincid cu bitii 11-15 ai lui A
        or bx, 0000111111100000b ;bitii 5-11 ai lui C au valoarea 1
        mov ecx, 0
        mov cx, [b] ; CX = b
        and cx, 0000111100000000b ; isolating bits 8-11 of B
        rol cx, 4; moving the isolated bits to 15-12
        or bx, cx ;bitii 12-15 ai lui C coincid cu bitii 8-11 ai lui B
        or ebx, 01110111010101110000000000000000b;;bitii 16-31 ai lui C coincid cu bitii lui A
        mov [c], ebx ; mutam rezultatul obtinut in dublucuvantul C 
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
