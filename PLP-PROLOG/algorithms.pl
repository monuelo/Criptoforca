shift(Word, Result):-   %nivel rasgado
    string_codes(Word, Aux),
    Aux = [A | B],
    append(B, [A], Aux2),
    string_codes(Result, Aux2).

sum(X, Y, S):- S is X+Y.

no_then_yes(Word, Result):- %nivel rasgado
    string_codes(Word, Aux),
    no_then_yes_aux1(Aux, Aux2),
    string_codes(Result, Aux2).

no_then_yes_aux1([], []).
no_then_yes_aux1([H|T], Result) :-
    no_then_yes_aux2(T, Rest),
    sum(H, 1, X),
    append([X], Rest, Result).

no_then_yes_aux2([], []).
no_then_yes_aux2([H|T], Result) :-
    no_then_yes_aux1(T, Rest),
    append([H], Rest, Result).


caesar1(Word, Result):-    %nivel facil
    string_codes(Word, Aux),
    maplist(plus(1), Aux, Aux2),
    string_codes(Result, Aux2).

caesar2(Word, Result):-    %nivel facil
    string_codes(Word, Aux),
    maplist(plus(2), Aux, Aux2),
    string_codes(Result, Aux2).


ascii(Word, Result):-    %nivel medio
    string_codes(Word, Aux),
    atomic_list_concat(Aux, '', Aux2),
    atom_string(Aux2, Result).


fibonacci(Word, Result):-  %nivel medio
    string_codes(Word,Aux),
    Aux = [A,B,C,D|E],
    fib(4,Temp1),    fib(5,Temp2),    fib(6,Temp3),    fib(7,Temp4),
    H is Temp1 + A,  I is Temp2 + B,  J is Temp3 + C,  K is Temp4 + D,
    is_in_ascii(H,W),
    is_in_ascii(I,X),
    is_in_ascii(J,Y),
    is_in_ascii(K,Z),
    maplist(plus(2), E, F),
    Aux2 = [W,X,Y,Z|F],
    string_codes(Result, Aux2).

fib(0, 1) :- !.
fib(1, 1) :- !.
fib(N, Result) :-
    N1 is N - 1,
    N2 is N - 2,
    fib(N1, Result1),
    fib(N2, Result2),
    Result is Result1 + Result2.

is_in_ascii(Char, Result):- (Char < 128 -> Result is Char; Result is (mod(Char, 128) + 32) ).

complementary(Word, Result):- %nivel medio
    string_codes(Word,Aux),
    Aux = [A,B,C,D|F],
    G is 122 - (A-97),
    H is 122 - (B-97),
    I is 122 - (C-97),
    J is 122 - (D-97),
    maplist(plus(4), F, N),
    Aux2 = [G,H,I,J|N],
    string_codes(Result,Aux2).


:- initialization(main).

main:-
	fibonacci("interessante", Result),
    write(Result), write("\n"),

    halt.
