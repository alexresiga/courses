%insert2(l1,..,ln, v, i, i2) =
%[], n=0
%l1 U v U insert2(l2,...,ln, v,i+1,i2*2), i=i2, n != 0
%l1 U insert2(l2,..,ln, v, i+1,i2), i!=i2
%insert2(L: list, V: integer, I:integer, I2:integer, R: list)
%insert2(i, i, i, i, o)
insert2([],_,_,_,[]).
insert2([H|T], V, I, I2, R) :- I =:= I2, INew is I+1, I2New is I2*2, insert2(T, V, INew, I2New, RL), R = [H,V|RL].
insert2([H|T], V, I, I2, R) :- I =\= I2, INew is I+1, insert2(T, V, INew, I2, RL), R = [H|RL].
