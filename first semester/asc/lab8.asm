loop et <=> dec ecx, cmp ecx, 0, jne et

mov ecx, 0
et:


loop et
---------------------------------------
x<'a'

cmp [x], 'a'
jl et
---------------------------------------
jl/ jg -> semn

jb/ ja -> fara semn


mov al, 0x12  ;00010010
mov bl, 0xEE  ;11101110
add al, bl   ;100000000

CF = 1
OF = 1
SF = 0
PF = 1
ZF = 1




mov al,     10111111b
mov bl,     00000001b
add al, bl;101000000b

cf 1
of 1
sf 0
pf 0 
zf 0

------------------------------------------
jumpurile se executa in functie de flaguri

-----------------------------------------

primul operand al opereatilor logice trebuie sa fie memorie
or 2, al INCORECT

-----------------------------------------
div ebx -> edx:eax
--------------------------------------

STD
mov esi, s
lodsb
esi = s-1

cld
mov esi, s
lodsb

esi = s+1


std
mov esi, s
stosd

esi = s 
stosd : [edi]<- EAX; EDI =  EDI - 4

---------------------------------------------

data segment
    a dd 0x0012345, 0xABCD
mem: -;45|23|01|00|CD|AB|00|00 ;+

mov ax, [a+5] ; -> AX = 00AB
mov eax, [a+3]; -> EAX = 

--------------------------------------------------
data segment
    a db 9
    b db 17
    x dq 0
    c equ $-b ; c = 9 bytes
 
-----------------------------------------------------
mov ax, 0ffh ; ==  0xFF
mov dx, 0
mov bx, 255 ; FF
idiv bx ; result is 1
