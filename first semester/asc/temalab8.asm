bits 32
global start        
extern exit
import exit msvcrt.dll
        ;int i = 0;
		;int j = 0;
		;while(i <= n && j <= m) {
		;	if(A[i] <= B[j]) {
		;		++ k;
		;		C[k] = A[i];
		;		++ i;	
		;	}
		;	else {
		;		++ k;
		;		C[k] = B[j];
		;		++ j;
		;	}
		;while(i <= n) {
		;	++ k;
		;	C[k] = A[i];
		;	++ i;
		;}
		;while(j <= m) {
		;	++ k;	
		;	C[k] = B[j];
		;	++ j;

segment data use32 class=data
    s1 db 'a', 'c','e', 0
    len1 equ $-s1
    s2 db 'b', 'd', 0
    len2 equ $-s2
    s3 times len1+len2 db 0


segment code use32 class=code
    start:
        mov esi, 0
        mov edi, 0
        mov ebx, 0
    bucla:
        cmp esi, len1
        ja final
        cmp edi, len2
        ja final
        mov al, [s1+esi]
        cmp al, [s2+edi]
        jbe addS1
        ja addS2
    addS1:
        
        mov [s3+ebx], al
        inc ebx
        inc esi
        jmp bucla
    addS2:
        mov bl, [s2+edi]
        mov [s3+ebx], bl
        inc ebx
        inc edi
        jmp bucla
    
    
    final:
        cmp esi, len1
        je addS2
        cmp edi, len2
        je addS1
        
        ; exit(0)
        push    dword 0
        call    [exit]
