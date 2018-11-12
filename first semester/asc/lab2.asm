;ADDITION
a + b
a, b = dwords

ADD dest, source
dest = dest + source
op1=mem-> register, constant
op2=reg-> mem,reg,constant


;SUBTRACTION
a - b
a,b dwords

Sub dest, source
dest = mem -> source = reg, constant
dest = reg -> source =  mem,reg,constant


(a+b) - ( c +d) = ? ;a,b,c,d:words 


; MULTIPLICATION
a * b
t1 * t2 = result
MUL term ;multiplication
;term can be memory or register 
size(result) = 2 * size(term)
term : byte => AL * term = AX ; we specify one term and the other one is implicit
term : word => AX * term = DX:AX
term : dword => EAX * term = EDX:EAX 


;DIVISION 

a/b 
deimp/ impart = rez (cat,rest)
divident/ divisor = quotient, remainder

DIV divisor
divisor : mem, reg
size(divident) = 2 * size(divisor) 
divisor: byte => AX / byte => AL = quotient, AH = remainder
divisor: word => DX:AX / word => AX = quotient, DX = remainder
divisor: dword => EDX:EAX / dword => EAX = quotient, EDX = remainder
