%subsets(l1..ln) =
%{ l1 U subsets(l2..ln) }
%{ subsets(l2..ln) }
%subsets(L: list, R: list)
%subsets(i, o)
subsets([], []).
subsets([H|T], R) :- subsets(T, RT), R = [H|RT].
subsets([_|T], R) :- subsets(T, R).

%listSum(l1..ln) =
%{ 0, n=0 }
%{ l1 + listSum(l2..ln) }
%listSum(L:list, S: int)
%listSum(i, o)
listSum([], 0).
listSum([H|T], S) :- listSum(T, ST), S is H+ST.

%oneSolution(L: list, R: list)
%oneSolution(i, o)
oneSolution(L, S, R) :- subsets(L, R), listSum(R, S).

allSolutions(L, S, R) :- findall(RO, oneSolution(L, S, RO), R).
