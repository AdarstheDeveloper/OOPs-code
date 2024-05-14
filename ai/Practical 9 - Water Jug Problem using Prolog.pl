/*
Initial State: move(0, 0, 0).
Goal State: move(2, Y, Z).
*/

member(X,[X|_]).
member(X,[Y|Z]):- member(X,Z).

move(X,Y,_):- X=:=2, Y=:=0, write('Complete!'), !. 
move(X,Y,Z):- X<4, \+member((4,Y),Z), write("Fill 4l jug"), nl, move(4,Y,[(4,Y)|Z]).
move(X,Y,Z):- Y<3, \+member((X,3),Z), write("Fill 3l jug"), nl, move(X,3,[(X,3)|z]).
move(X,Y,Z):- X>0, \+member((0,Y),Z), write("Empty 4l jug"), nl, move(0,Y,[(0,Y)|Z]).
move(X,Y,Z):- Y>0, \+member((X,0),Z), write("Empty 3l jug"), nl, move(X,0,[(X,0)|Z]).
move(X,Y,Z):- P is X+Y, P>=4, Y>0, K is 4-X, M is Y-K, \+member((4,M),Z), write("Fill 4l jug using 3l jug"), nl, move(4,M,[(4,M)|Z]).
move(X,Y,Z):- P is X+Y, P>=3, X>0, K is 3-Y, M is X-K, \+member((M,3),Z), write("Fill 3l jug using 4l jug"), nl, move(M,3,[(M,3)|Z]).
move(X,Y,Z):- K is X+Y, K<4, Y>0, \+member((K,0),Z), write("Pour all of 3l jug into 4l jug"), nl, move(K,0,[(K,0)|Z]).
move(X,Y,Z):- K is X+Y, K<3, X>0, \+member((0,K),Z), write("Pour all of 4l jug into 3l jug"), nl, move(0,K,[(0,K)|Z]).