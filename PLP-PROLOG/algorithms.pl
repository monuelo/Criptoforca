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
    fibonacciAux(Aux, Aux2, 0),
    string_codes(Result, Aux2).

fibonacciAux(List, Result, N):-
    List = [X|Y],
    fib(N,Fib),
    X1 is X + Fib,
    sum(N,1,M),
    append([X1], Result),
    (Y =\= [] -> fibonacciAux(Y, Result, M); !).

fib(0, 1) :- !.
fib(1, 1) :- !.
fib(N, Result) :-
    N1 is N - 1,
    N2 is N - 2,
    fib(N1, Result1),
    fib(N2, Result2),
    Result is Result1 + Result2.


complementary(Word, Result):- %nivel medio
    string_codes(Word,Aux),
    Aux = [X|Y],
    X is 122 - X,
    append(X,Result),
    complementary(Y, Result).


:- initialization(main).

main:-
	fibonacci("interessante", Result),
    write(Result), write("\n"),

    halt.
