bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
   ; a-byte; b-doubleword; c-qword
    a db 5
    b dd 4
    c dq 3

; our code starts here
segment code use32 class=code
    start:
        ;c+(a*a-b+7)/(2+a) SIGNED
        mov al, [a]
        mov ah, [a]
        imul ah ;AX = a*a word 
        cwd ;dx:ax = a*a doubleword
        sub ax, [b]
        sbb dx, [b+2] ;dx:ax= a*a - b 
        mov bx, word 7
        mov cx, 0
        add ax, bx
        adc dx, cx ; a*a-b+7 is in dx:ax 
        push dx
        push ax
        pop eax ; eax = a*a-b+7
        mov ebx, eax ;EBX = EAX = a*a-b+7 
        mov al, [a] ;AL = a 
        add al, byte 2 ; AL= a+2
        cbw ;byte AL becomes word AX = a+2 
        mov cx, ax ; CX = AX = a+2
        mov eax, ebx ;EAX = EBX 
        idiv cx ;AX = quotient of EAX (a*a-b+7)/(a+2) CX 
        cwde ;word AX becomes dword extended EAX
        cdq  ;EAX becomes qword EDX:EAX
        add eax, [c]
        adc edx, [c+4] ;edx:eax = c + (a*a-b+7)/(a+2)
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
