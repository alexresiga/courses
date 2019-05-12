%insert(E, l1..ln) =
%{E U insert(E, l2..ln),E > l1 }
%{ E U l1, n=1 }
%insert(A: int, L: list, R: list)
%insert(i,i,o)
insert(A, [H|T], R) :- A > H, !, insert(A, T, RT), R=[H|RT].
insert(A, T, [A|T]).


%sorting(l1..ln) =
%{ [], n = 0 }
%{ insert(l1, sorting(l2...ln)),otherwise }
%sorting(L:list, R:list)
%sorting(i, o)
sorting([], []).
sorting([H|T], R) :- sorting(T, RT), insert(H, RT, R).

%sortList(L: list, R: list)
%sortList(i, o)
sortList([], []).
sortList([H|T], R) :- is_list(H), sorting(H, RH), sortList(T, RT), R=[RH|RT].
sortList([H|T], R) :- atom(H);number(H), sortList(T, RT), R=[H|RT].
