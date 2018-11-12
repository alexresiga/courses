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
        ;c+(a*a-b+7)/(2+a) UNSIGNED
        mov al, [a] ; AL = a byte
        mov ah, [a] ; AH = a byte 
        mul ah      ; AX = a*a = AL*AH word
        mov dx, 0   ; DX = 0 word 
        mov bx, dx  ; BX = 0 word 
        shl ebx, 16 ; shifting the bits of BX to the left with 16 bits 
        mov bx, ax  ; BX = AX = a*a word ; now EBX is a doubleword containing a*a
        sub ebx, [b]; EBX = a*a - b doubleword
        add ebx, dword 7 ;EBX = a*a - b +7 
        mov cl, [a]   ;AL = a byte 
        add cl, byte 2;AL = a + 2 byte 
        mov ch, 0 ;AX = AL = a+2 word 
        mov eax, ebx ;EAX = EBX = (a*a-b+7)/(a+2) doubleword
        div cx   ;AX = quotient DX = remainder
        mov dx, 0;DX = 0
        mov bx, dx;BX = 0
        shl ebx, 16;shifting the bits of BX to the left with 16 bits 
        mov bx, ax ;BX = AX = quotient word ; now EBX is a doubleword containing the quotient
        mov ecx, 0 ;ecx:ebx = quotient of division ;ecx:ebx = (a*a-b+7)/(2+a)
        add ebx, dword [c]
        adc ecx, dword [c+4] ;ecx:ebx = c + (a*a-b+7)/(2+a)
       
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
