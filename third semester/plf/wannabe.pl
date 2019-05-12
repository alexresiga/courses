%prod elem pare din lista
%prod(L: list, R: int)
%prod(i, o)

prod([], 1).
prod([H|T], R) :- H mod 2 =:= 0, prod(T, RT), R is H*RT.
prod([H|T], R) :- H mod 2 =:= 1, prod(T, R).

prodC([],C, C).
prodC([H|T], C, R) :- H mod 2 =:= 0, C2 is C*H, prodC(T, C2, R).
prodC([H|T], C, R) :- H mod 2 =\= 0, prodC(T, C, R).

%apElem(L: list, E: int, R: int)
%apElem(i, i, o)
apElem([], _,0).
apElem([H|T], E, R) :- E =:= H, apElem(T, E, RT), R is 1 + RT.
apElem([H|T], E, R) :- E =\= H, apElem(T, E, R).

apElemC([], _, C, C).
apElemC([H|T], E, C, R) :- E =:= H, C2 is C+1, apElemC(T, E, C2, R).
apElemC([H|T], E, C, R) :- E =\= H, apElemC(T, E, C, R).

%insertP(L: list, E: int, P: int, IDX: int, R: list)
%insertP(i, i, i, i, o).
insertP([],_,_,_,[]).
insertP(L, E, P, I, R) :- P =:= I, I2 is I+1, insertP(L, E, P, I2, RT), R = [E|RT].
insertP([H|T], E, P, I, R) :- P =\= I, I2 is I+1, insertP(T, E, P, I2, RT), R = [H|RT].

%gcd(A: int, B: int, R: int)
%gcd(i, i, o)
gcd(0,0,0).
gcd(A, B, R) :- A =:= 0;B =:= 0, R is A+B.
gcd(A, B, A) :- A =:= B.
gcd(A, B, R) :- A > B, A2 is A-B, gcd(A2, B, RT), R is RT.
gcd(A, B, R) :- B > A, B2 is B-A, gcd(A, B2, R).

%lcm(A: int, B: int, R: int)
%lcm(i, i, o)
lcm(A, B, 0) :- A =:= 0; B=:=0.
lcm(A, B, R) :- A =\= 0, B =\= 0,gcd(A,B, RT), R is A*B div RT.

%lcmList(L:list, R: int)
%lcmList(i, o)
lcmList([], 1).
lcmList([H|T], R) :- lcmList(T, RT), lcm(H, RT, R).

%delete(L: list, E: int, I: int, R: list)
%delete(i, i, i, o)
delete([],_,_,[]).
delete([H|T], E, I, R) :- I mod 2 =:= 0, H =:= E, I2 is I+1, delete(T, E, I2, R).
delete([H|T], E, I, R) :- I mod 2 =:= 0, H =\= E, I2 is I+1, delete(T, E, I2, RT), R = [H|RT].
delete([H|T], E, I, R) :- I mod 2 =\= 0, I2 is I+1, delete(T, E, I2, RT), R = [H|RT].

main([],[]).
main(L, R) :- lcmList(L, LCM), delete(L, LCM, 1, R).

%poz(L: list, i: int, R: list)
%poz(i, i, o)
poz([], _, []).
poz([H|T], I, R) :- H mod 3 =:= 0, IT is I+1, poz(T, IT, RT), R = [I|RT].
poz([H|T], I, R) :- H mod 3 =\= 0, IT is I+1, poz(T, IT, R).

min2(A, B, A) :- A =< B.
min2(A, B, B) :- A > B.

minList([], 0).
minList([H], H).
minList([H|T], R) :- minList(T, RT), min2(H, RT, R).

revListC([], C, C).
revListC([H|T], C, R) :- is_list(H),CH = [], revListC(H,CH, RH), C2 = [RH|C], revListC(T, C2, R).
revListC([H|T], C, R) :- C2 = [H|C], revListC(T, C2, R).



makeSet([], []).
makeSet([H|T], R) :- apElem([H|T], H, C), C > 1, makeSet(T, R).
makeSet([H|T], R) :- apElem([H|T], H, C), C =:= 1, makeSet(T, RT), R=[H|RT].

%remove(L: List, E: int, R: List)
%remove(i,i,o)
remove([],_,[]).
remove([H|T], E, R) :- H =:= E, remove(T, E, R).
remove([H|T], E, R) :- H =\= E, remove(T, E, RT), R=[H|RT].

removeOne([], _, []).
removeOne([H|T], E, T) :- H =:= E.
removeOne([H|T], E, R) :- H =\= E, removeOne(T, E, RT), R = [H|RT].
%sortInc(L: list, R: list)
%sortInc(i, o)
sortInc([], []).
sortInc([H|T], R) :- minList([H|T], MIN), removeOne([H|T], MIN, SORTED), sortInc(SORTED, RT), R = [MIN|RT].

%factorial(N: int, R: int)
%factorial(i, o)
factorial(0, 1).
factorial(N, R) :- N2 is N-1, factorial(N2, RT), R is RT*N.

%rev(N: int, C: int, R: int)
%rev(i, i, o)
rev(0, C, C).
rev(N, C, R) :- NDIV is N div 10, NMOD is N mod 10, C2 is C*10 + NMOD, rev(NDIV, C2, R).

%freq(L: list, R: list)
%freq(i, o)
freq([], []).
freq([H|T], R) :- apElem([H|T], H, C),remove(T, H, RL), freq(RL, RT), R = [[H,C]|RT].


%formList(N: int, R: list)
%formList(i, o)
formList(0, C, C).
formList(N, C, R) :- NMOD is N mod 10, NDIV is N div 10, C2 = [NMOD|C], formList(NDIV,C2,R).

form2([], C, C).
form2([H|T], C, R) :- C2 is C*10+H, form2(T, C2, R).

finallyMain([], []).
finallyMain(L, R) :- form2(L, 0, NR), NR2 is NR-1, formList(NR2, [], R).

%consEven(L: list, R: list)
%consEven(i, o)
%nu merge
consEven([], []).
consEven([H|T], R) :- H mod 2 =:= 0, consEven(T, RT), R = [H|RT].
consEven([H|T], R) :- H mod 2 =\= 0, consEven(T, R), R = [].

%prime(N: int, D: int, R: result)
%prime(i, i, o)
prime(N, _, 0) :- N < 2, !.
prime(2, _, R) :- R is 1.
prime(N, _, R) :- N mod 2 =:= 0, R is 0.
prime(N, D, R) :- J is N div 2, D =< J, N mod D =\= 0, D2 is D+1, prime(N, D2, R).
prime(N, D, R) :- J is N div 2, D =< J, N mod D =:= 0, R is 0.
prime(N, D, R) :- J is N div 2, D > J, R is 1.

deleteP([], _,[]).
deleteP([_|T], P, R) :- prime(P, 2, D),D is 1, P2 is P+1, deleteP(T, P2, R).
deleteP([H|T], P, [H|RT]) :- prime(P, 2, D), D is 0, P2 is P+1, deleteP(T, P2, RT).

in([], _, 0).
in([H|_], E, R) :- H =:= E, R is 1.
in([H|T], E, R) :- H =\= E, in(T, E, R).

newPrime(1,_) :- cut.
newPrime(N,D) :-D > N div 2.
newPrime(N,D) :-N mod D =\=0, DD is D+1, newPrime(N,DD).

removePrime([], []).
removePrime([H|T], R) :- prime(H,2, RP), RP is 1, removePrime(T, R).
removePrime([H|T], [H|R]) :- prime(H, 2, RP), RP is 0, removePrime(T, R).


perm([], []).
perm([H|T], R) :- perm(T, RT), insertP(H, RT, R).

comb(_, 0, []).
comb([H|T], K, R):- K > 0, KT is K-1, comb(T, KT, RT), R = [H|RT].
comb([_|T], K, R):- K > 0, comb(T, K, R).

aranj([], _, []).
aranj(L, K, R) :- comb(L, K, C), perm(C, R).

subsets([], []).
subsets([H|T], R) :- subsets(T, RT), R = [H|RT].
subsets([_|T], R):- subsets(T, R).

size([], 0).
size([_|T], R) :- size(T, RT), R is RT + 1.


onesol(L, R) :- subsets(L, RL), size(RL, S), S mod 2 =:= 0, R = RL.
allsol(L, R) :- findall(RO, onesol(L, RO), R).

removeHelper([], _, _, []).
removeHelper([_|T], N, P, R) :- P =:= N, NT is N*2, PT is P+1, removeHelper(T, NT, PT, R).
removeHelper([H|T], N, P, R) :- P =\= N, PT is P+1, removeHelper(T, N, PT, RT), R=[H|RT].

removeMain(L, N, R):- removeHelper(L, N, 1, R).

verificare([]).
verificare([_, _|T]) :- verificare(T).

sumN(0, 0).
sumN(N, R):- N >= 0, N2 is N-1, sumN(N2, RN), R is RN + N.

sumNC(0, C, C).
sumNC(N, C, R) :- N >= 0, N2 is N-1, C2 is C+N, sumNC(N2, C2, R).

este_prim(1, _):- !.
este_prim(N,K) :- I is N div 2 , K > I, !.
este_prim(N,K) :- P is N mod K , P =\= 0 , K2 is K + 1 , este_prim(N,K2).

baga_final(E,[],[E]).
baga_final(E,[H|T],[H|R]) :- baga_final(E,T,R).

swap([],[]).
swap([H|T],R) :- swap(T,R2) , baga_final(H,R2,R).

gen(C, N,[]) :-  C > N.
gen(C, N, R):- C =< N, CT is C+1, gen(CT, N, RT), R=[C|RT].

generate(N, R) :- gen(N, 2*N-1, R).

verif([_]).
verif([H1,H2|T]) :- H1 - H2 >= 0, H1-H2 =< 2, verif([H2|T]).
verif([H1,H2|T]) :- H2 - H1 >= 0, H2-H1 =< 2, verif([H2|T]).

myinsert([], E, [E]).
myinsert([H|T], E, R) :- R = [E, H|T].
myinsert([H|T], E, R) :- myinsert(T, E, RT), R = [H|RT].

myperm([], []).
myperm([H|T], R) :- myperm(T, RT), myinsert(RT, H, R).

onesol1(N, R) :- generate(N, L), myperm(L, R).
allsol1(N, R) :- findall(RO, onesol1(N, RO), R).

isP(N, D):-N=:=D,true,!.
isP(N,_):-N < 2, !, false.
isP(N, D):-N mod D =:=0, !, false.
isP(N, D):-N mod D =\=0, D1 is D+1, isP(N,D1).

findE([],_, 0).
findE([H|T], E, R) :- is_list(H), findE(H, E, RH), findE(T, E, RT), R is RH+RT.
findE([H|T], E, R) :- H =\= E, findE(T, E, R).
findE([H|_], H, 1):- true, !.

isPrime(X,X).
isPrime(X,D):-X > 2, X mod D =\= 0, D1 is D+1, isPrime(X,D1).
