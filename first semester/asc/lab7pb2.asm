bits 32

global start        

extern exit
import exit msvcrt.dll
; LODSD eax <- esi
; if DF=0 esi+=4
; if DF=1 esi-=4
; LODSB, LODSW
;STOSD edi <- eax
; if df = 0 edi+=4
; if df = 1 edi-=4
; STOSB STOSW
segment data use32 class=data
    s dd 1, 2, 3, 4
    len equ ($-s)/4
    d resd len

segment code use32 class=code
    start:
       ; d[i] = s[i]+1
       mov ecx, len
       jecxz final
       mov esi, s
       cld
       mov edi, d
       b:
        ;eax <- el curent
        lodsd
        inc eax
        ; d[i] <- EAX
        ;mov [d+edi], eax
        stosd ;[edi] <- EAX edi+=4
        ;LODSD+STOSD = MOVSD
        loop b
        ; B = REP MOVSD REPEAT FOLLOWING INSTRUCTION ECX TIMES
            
            
        final:
        ; exit(0)
        push    dword 0
        call    [exit]
