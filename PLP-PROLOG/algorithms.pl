shift(Word, Result):-
    string_codes(Word, Aux),
    Aux = [A | B],
    append(B, [A], Aux2),
    string_codes(Result, Aux2).

sum(X, Y, S):-
    S is X+Y.

caesar(Word, Result):-
    string_codes(Word, Aux),
    maplist(plus(1), Aux, Aux2),
    string_codes(Result, Aux2).


no_then_yes(Word, Result):-
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


:- initialization(main).

main:-
	no_then_yes("iaeblz", Result),
    write(Result), write("\n"),
    halt.
