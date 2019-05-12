%max2(a, b) =
%{ a, a >= b }
%{ b, b > a }
%max2(A: int, B:int, R: int)
%max2(i, i, o)
max2(A, B, A) :- A >= B.
max2(A, B, B) :- B > A.

%maxList(l1..ln) =
%{ 0, n=0 }
%{ max(l1, maxList(l2..ln)), otherwise }
%maxList(L: list, R: int)
%maxList(i, o)
maxList([], 0).
maxList([H|T], R) :- maxList(T, RT), max2(H, RT, R).


%sub(l1..ln, e, p) =
%{ [], n=0 }
%{ l1+e U sub(l2..ln, e, p+1), p%2 = 0 }
%{ l1 U sub(l2..ln), e, p+1), p%2 != 0 }
%sub(L:list, E: int,P: int, R: list)
%sub(i, i, o)
sub([],_, _, []).
sub([H|T], E, P, R) :- P mod 2 =:= 0, NEW is H+E, sub(T, E, P+1, RT), R = [NEW|RT].
sub([H|T], E, P, R) :- P mod 2 =\= 0, sub(T, E, P+1, RT), R = [H|RT].

main([], []).
main(L, R) :- maxList(L, ML), sub(L, ML, 1, R).
