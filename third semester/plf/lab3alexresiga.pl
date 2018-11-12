%insert(A, [], [A]).
insert(A, [H|T], R) :- A >= H, insert(A, T, RT), R is RT.
insert(A, [H|T], [A,H|T]) :- A < H.
