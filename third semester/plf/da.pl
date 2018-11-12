%gcd(i, i, o)
gcd(0, 0, 0).
gcd(A, 0, A).
gcd(0, B, B).
gcd(A, B, R) :- A>B, L is A-B, gcd(L, B, R).
gcd(A, B, R) :- A<B, L is B-A, gcd(A, L, R).
gcd(A, B, R) :- A =:= B, R is A.

%lcm(A: Integer, B: Integer, R: Integer)
%lcm(i, i, o)
lcm(A, B, 0) :- A =:= 0; B =:= 0.
lcm(A, B, R) :- A =\= 0, B =\= 0, gcd(A, B, RL), R is A*B div RL.

%lcmList(L: List, R: Integer)
%lcmList(i, o)
lcmList([],0).
lcmList([H|T], R) :- lcmList(T, RT), lcm(H, RT, R) .

