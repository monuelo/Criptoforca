:- use_module(library(apply)).
:- use_module(library(csv)).
:- consult(algorithms).

setup_words :-
    reconsult('palavras.pl').

encrypt(Word, 1, Result) :-
    shift(Word, Result).

encrypt(Word, 2, Result) :-
    no_then_yes(Word, Result).

encrypt(Word, 3, Result) :-
    caesar1(Word, Result).

encrypt(Word, 4, Result) :-
    caesar2(Word, Result).

encrypt(Word, 5, Result) :-
    ascii(Word, Result).

encrypt(Word, 6, Result) :-
    fibonacci(Word, Result).

encrypt(Word, 7, Result) :-
    complementary(Word, Result).

encrypt(Word, 8, Result) :-
    cryptomix(Word, Result).

write_word_file :-
    setup_words,
	tell('palavras.pl'),nl,
	listing(word/3),
	told.

compare_to(<,A,B) :-
    nth0(1,A,X),
    nth0(1,B,Y),
    X =< Y.
compare_to(>,_,_).

compare_to(<,A,B) :-
    nth0(1,A,X),
    nth0(1,B,Y),
    X =< Y.
compare_to(>,_,_).


get_spaces(0, "").
get_spaces(Quantity, Result):-
	Quantity1 is Quantity-1,
	get_spaces(Quantity1, Result1),
	string_concat(" ", Result1, Result).

get_length_spacing(Size, SizeScore, Result):-
	compare(>, SizeScore, 2),
	Value is Size - (SizeScore - 2),
	get_spaces(Value, Result).

get_length_spacing(Size, _, Result):-
	get_spaces(Size, Result).


write_word(Text, Theme):-
    get_level(Text, Level),
    string_lower(Text, TextLowerCase),
    atom_string(TextAtom, TextLowerCase),
    string_lower(Theme, ThemeLowerCase),
    atom_string(ThemeAtom, ThemeLowerCase),
    assertz(word(TextAtom, ThemeAtom, Level)),
    write_word_file.

get_word_text(Word, Text):-
    nth0(0, Word, Text).

leveled_fast_match:-
    setup_words,
    select_level(Level),
    findall([Text, Theme, Level], word(Text, Theme, Level), Result),
    get_random_word(Result, RandomWord),
    get_word_text(RandomWord, WordText),
    X is Level*2+1,
    Y is X-2,
    random(Y, X, Cryptography),
    encrypt(WordText, Cryptography, EncryptedWord),
    start_game(WordText, Score, EncryptedWord).

random_fast_match:-
    setup_words,
    findall([Text, Theme, Level], word(Text, Theme, Level), Result),
    get_random_word(Result, RandomWord),
    get_word_text(RandomWord, WordText),
    start_game(WordText, Score).

get_random_word(Words, RandomWord):-
    length(Words, Size),
    random(0, Size, RandomIndex),
    nth0(RandomIndex, Words, RandomWord).

get_option(Option) :-
    write("\n\n                    Informe o número da opção desejada: "),
    read(Option).

select_menu_option(1) :- leveled_fast_match.
select_menu_option(2) :- show_rules.
select_menu_option(3) :- get_word_data.
select_menu_option(4) :- quit.
select_menu_option(_) :- show_invalid_option_message.

clear_screen :-
    tty_clear.

pause :-
    get_char(_),
    get_char(_),
    clear_screen.

sleep_3s :-
    sleep(3).

exit :-
    sleep_3s,
    halt.

intro :-
        clear_screen,
 writeln("      ____________..___________                                                                "),
    writeln("      | .___________))__________|                                                              "),
    writeln("      | | / /       ||                                                                         "),
    writeln("      | |/ /        ||              _____      _       _         __                            "),
    writeln("      | | /         ||.-''.        / ____|    (_)     | |       / _|                            "),
    writeln("      | |/          |/  _  \\      | |     _ __ _ _ __ | |_ ___ | |_ ___  _ __ ___ __ _         "),
    writeln("      | |           ||  `/,|      | |    | '__| | '_ \\| __/ _ \\|  _/ _ \\| '__/ __/ _` |     "),
    writeln("      | |           (\\\\`_.'       | |____| |  | | |_) | || (_) | || (_) | | | (_| (_| |       "),
    writeln("      | |          .-`--'.         \\_____|_|  |_| .__/ \\__\\___/|_| \\___/|_|  \\___\\__,_|   "),
    writeln("      | |         /Y . . Y\\                   | |                                              "),
    writeln("      | |        // |   | \\\\                  |_|                                             "),
    writeln("      | |       //  | . |  \\\\                                                                 "),
    writeln("      | |      ')   | _ |   (`                                                                  "),
    writeln("      | |           || ||                                                                       "),
    writeln("      | |           || ||                              OFERECIMENTO: PLP                  "),
    writeln("      | |           || ||                                                                       "),
    writeln("      | |           || ||                                                                       "),
    writeln("      | |          / | | \\                                                                     "),
    writeln("      | |          `-' `-'                                                                      "),
    writeln("      |_|                                                                                       "),
    writeln("                                   Aguarde...                                   "),
    sleep_3s.

menu :-
    clear_screen,
    writeln("\n---------------------------------     MENU     ---------------------------------\n\n"),
    writeln("                                1  -  Jogar"),
    writeln("                                2  -  Instruções"),
    writeln("                                3  -  Cifrar Palavra"),
    writeln("                                4  -  Sair"),
    get_option(Option),
    select_menu_option(Option).

show_invalid_option_message :-
    writeln("           Opção inválida... Pressione ENTER para tentar novamente!\n"),
    pause,
    menu.

doll_draw(Lives) :-
        clear_screen,
    doll_draw_body(Lives).

doll_draw_body(5) :-
    writeln("\n\n      _______"),
    writeln("     |"),
    writeln("     |"),
    writeln("     |"),
    writeln("     |"),
    writeln("     |"),
    writeln("    _|_"),
    writeln("   |   |______"),
    writeln("   |__________|\n\n").

doll_draw_body(4) :-
    writeln("\n\n      _______"),
    writeln("     |       |"),
    writeln("     |      (_)"),
    writeln("     |"),
    writeln("     |"),
    writeln("     |"),
    writeln("    _|_"),
    writeln("   |   |______"),
    writeln("   |__________|\n\n").

doll_draw_body(3) :-
    writeln("\n\n      _______"),
    writeln("     |       |"),
    writeln("     |      (_)"),
    writeln("     |      /|"),
    writeln("     |"),
    writeln("     |"),
    writeln("    _|_"),
    writeln("   |   |______"),
    writeln("   |__________|\n\n").

doll_draw_body(2) :-
    writeln("\n\n      _______"),
    writeln("     |       |"),
    writeln("     |      (_)"),
    writeln("     |      /|\\"),
    writeln("     |"),
    writeln("     |"),
    writeln("    _|_"),
    writeln("   |   |______"),
    writeln("   |__________|\n\n").

doll_draw_body(1) :-
    writeln("\n\n      _______"),
    writeln("     |       |"),
    writeln("     |      (_)"),
    writeln("     |      /|\\"),
    writeln("     |      /"),
    writeln("     |"),
    writeln("    _|_"),
    writeln("   |   |______"),
    writeln("   |__________|\n\n").

draw_victory_doll :-
    clear_screen,
    writeln("\n\n      _______"),
    writeln("     | *    *     *"),
    writeln("     |   *   *"),
    writeln("     |  *      *"),
    writeln("     |      *      *"),
    writeln("     |   \\(*-*)/"),
    writeln("    _|_     | "),
    writeln("   |   |___/_\\_"),
    writeln("   |__________|\n\n"),
    writeln("YOU WIN!"),
    sleep_3s,
    menu.

draw_defeat_doll :-
    clear_screen,
    writeln("\n\n      _______"),
    writeln("     |       |"),
    writeln("     |     (x_x)"),
    writeln("     |      /|\\"),
    writeln("     |      / \\"),
    writeln("     |"),
    writeln("    _|_"),
    writeln("   |   |______"),
    writeln("   |__________|\n\n"),
    writeln("YOU LOSE!"),
    sleep_3s,
    menu.

select_theme(Theme) :-
    clear_screen,
    writeln("\n----------------------------     SELECIONAR TEMA     ---------------------------\n\n"),
    show_themes,
    get_option(Option),
    get_themes(Themes),
    Option1 is Option - 1,
    nth0(Option1, Themes, Theme).

select_level(Option) :-
    clear_screen,
    writeln("\n---------------------------     SELECIONAR NÍVEL     --------------------------\n\n"),
    show_levels,
    get_option(Option).

show_themes :-
    get_themes(Themes),
    print_themes(Themes, 1).

print_themes([], _).
print_themes([Head|Tail], Index) :-
    string_concat("                              ", Index, SpacesAndIndex),
    string_concat(SpacesAndIndex, "  -  ", SpacesIndexAndDash),
    string_concat(SpacesIndexAndDash, Head, CompleteString),
    writeln(CompleteString),
    Index1 is Index + 1,
    print_themes(Tail, Index1).

show_levels :-
    clear_screen,
   writeln("\n------------------------     SELECIONAR DIFICULDADE     ------------------------\n\n"),
    writeln("                              1  -  Rasgado"),
    writeln("                              2  -  Facil"),
    writeln("                              3  -  Medio"),
    writeln("                              4  -  Enigma").

show_rules :-
    clear_screen,
    writeln("\n--------------------------------     REGRAS     --------------------------------\n\n\n"),

    writeln("     O jogo funciona como um jogo da forca comum, porém o jogador terá acesso à uma "),
    writeln("criptografia da palavra a ser adivinhada. O jogador poderá escolher entre 4 niveis  "),
    writeln(" de dificuldade ( Rasgado, Fácil, Médio e Enigma ) os quais farão uso das seguintes    "),
    writeln(" seguintes criptografias:                                                             "),
    writeln(" 1 - Shift         = Transporta a primeira letra para o fim da palavra                "),
    writeln(" 2 - Cesar1         = Soma 1 no codigo ASCII de cada letra da palavra                  "),
    writeln(" 3 - Cesar2         = Soma 2 no codigo ASCII de cada letra da palavra                  "),
    writeln(" 4 - NoThenYes     = Realiza Cesar1 em letras alternadas                               "),
    writeln(" 5 - ASCII         = Mostra o codigo ASCII de cada letra da palavra                   "),
    write(" 6 - Fibonacci       = Incrementa ao código ascii das 4 primeiras letras da palavra valores "),
    writeln("da sequencia de Fibonacci e realiza Cesar5 no restante"),
    writeln(" 7 - Complementary = substitui as 4 primeiras letras por sua complementar no alfabeto e realiza cesar4 no restante."),
    writeln(" 8 - Cryptomix     = realiza a seguinte sequencia de criptografias: shift, cesar2, NoThenYes, Fibonacci e inverte a palavra"),
    writeln("                         [ Pressione ENTER para voltar ]\n\n\n"),
    pause,
    menu.

show_victory_message :-
    clear_screen,
    writeln("                       \n Você é esperto... Foi um bom jogo.\n\n"),
    draw_victory_doll.

show_game_over_message :-
    clear_screen,
    writeln("                       \n Parece que essa cifra é forte demais pra você, né? HAHA...\n\n"),
    draw_defeat_doll.


get_word_data :-
    clear_screen,
    writeln("\n---------------------------     CIFRAR PALAVRA     --------------------------\n\n\n"),
    write("          Informe a palavra: "),
    read(Word),
    writeln(""),
    writeln(" 1 - Shift         = Transporta a primeira letra para o fim da palavra                "),
    writeln(" 2 - Cesar1         = Soma 1 no codigo ASCII de cada letra da palavra                  "),
    writeln(" 3 - Cesar2         = Soma 2 no codigo ASCII de cada letra da palavra                  "),
    writeln(" 4 - NoThenYes     = Realiza Cesar em letras alternadas                               "),
    writeln(" 5 - ASCII         = Mostra o codigo ASCII de cada letra da palavra                   "),
    writeln(" 6 - Fibonacci     = Incrementa ao código ascii da k-ésima letra da palavra o k-esimo   "),
    writeln("    valor da sequencia de Fibonacci, para uma palavra de n letras e para 0 < k <= n   "),
    writeln(" 7 - Complementary  = substitui a cada letra por sua complementar no alfabeto.          "),
    writeln("    Por exemplo: a -> z; b -> y; c -> x; etc...                                        "),
    writeln(" 8 - Cryptomix     = realiza a seguinte sequencia de criptografias: shift, cesar,      "),
    writeln("    complementary e fibonacci                                                         "),
    write("          Selecione a cifragem: "),
    read(Cipher),
    encrypt(Word, Cipher, Result),
    write("          Palavra Cifrada: "), writeln(Result),
    sleep_3s,
    menu.


quit :-
    clear_screen,
  writeln("\n-----------------------------     #$&!CRIPTOForca#$&!     -----------------------------\n\n"),
    writeln("\n\n                                                                                         "),
     writeln("            .oPYo.        o          o          d'b                                         "),
     writeln("           8    8                   8          8                                            "),
    writeln("            8      oPYo. o8 .oPYo.  o8P .oPYo. o8P  .oPYo. oPYo. .oPYo. .oPYo.              "),
     writeln("           8      8  `'  8 8    8   8  8    8  8   8    8 8  `' 8    ' .oooo8               "),
    writeln("            8    8 8      8 8    8   8  8    8  8   8    8 8     8    . 8    8               "),
     writeln("           `YooP' 8      8 8YooP'   8  `YooP'  8   `YooP' 8     `YooP' `YooP8              "),
     writeln("            :.....:..:::::..8 ....:::..::.....::..:::.....:..:::::.....::.....:              "),
     writeln("            ::::::::::::::::8 :::::::::::::::::::::::::::::::::::::::::::::::::              "),
     writeln("          ::::::::::::::::..:::::::::::::::::::::::::::::::::::::::::::::::::          "),
     writeln("                              - * - UM OFERECIMENTO - * -                               "),
     writeln("                   [PLP@UFCG] [Computação@UFCG] [Eles@Computação]                  \n\n"),
    exit.


get_hidden_word(Word, HiddenWord):-
    string_chars(Word, CharList),
    get_hidden_word_chars(CharList, HiddenWordChars),
    string_chars(HiddenWord, HiddenWordChars).

get_hidden_word_chars([], []).
get_hidden_word_chars([' '|Tail], HiddenWordChars):-
    get_hidden_word_chars(Tail, HiddenWordCharsAux),
    HiddenWordChars = [' '|HiddenWordCharsAux].
get_hidden_word_chars([Head|Tail], HiddenWordChars):-
    Head \= ' ',
    get_hidden_word_chars(Tail, HiddenWordCharsAux),
    HiddenWordChars = ['_'|HiddenWordCharsAux].

get_score(_, 0, _, 0):-!.
get_score(Word, Lives, HintsUsed, Score):-
    setup_words,
    word(Word, _, Level),
    string_length(Word, Length),
    Score is Length * Level * Lives + 50 * Level - 25 * HintsUsed.

reveal_letter(Word, HiddenWord, Letter, Result):-
    string_chars(Word, WordChars),
    string_chars(HiddenWord, HiddenWordChars),
    reveal_letter_chars(WordChars, HiddenWordChars, Letter, ResultChars),
    string_chars(Result, ResultChars).

reveal_letter_chars([], [], _, []).
reveal_letter_chars([Letter|WordTail], ['_'|HiddenWordTail], Letter, ResultChars):-
    reveal_letter_chars(WordTail, HiddenWordTail, Letter, ResultCharsAux),
    ResultChars = [Letter|ResultCharsAux].
reveal_letter_chars([_|WordTail], [HiddenWordHead|HiddenWordTail], Letter, ResultChars):-
    reveal_letter_chars(WordTail, HiddenWordTail, Letter, ResultCharsAux),
    ResultChars = [HiddenWordHead|ResultCharsAux].

show_guesses([], '').
show_guesses([GuessesHead], GuessesHead).
show_guesses([GuessesHead|GuessesTail], Result):-
    show_guesses(GuessesTail, ResultAux),
    string_add_space(GuessesHead, GuessesHeadWithSpace),
    string_concat(GuessesHeadWithSpace, ResultAux, Result).

string_add_space(String, StringWithSpace):-
    string_concat(String, ' ', StringWithSpace).

guess_letter(Word, Guesses, HintsUsed, HintsUsedAux, Result):-
    writeln("Digite uma letra ou [1] para dica: "),
    read(Letter),
    guess_letter_aux(Word, Guesses, Letter, HintsUsed, HintsUsedAux, Result).

guess_letter_aux(Word, Guesses, 1, HintsUsed, HintsUsedAux, Tip):-
    get_tip(Word, Guesses, Tip),
    HintsUsedAux is HintsUsed + 1, !.

guess_letter_aux(Word, Guesses, Letter, HintsUsed, HintsUsedAux, Result):-
    member(Letter, Guesses),
    writeln("Essa letra já foi sugerida. Tente outra!"),
    guess_letter(Word, Guesses, HintsUsed, HintsUsedAux, Result), !.

guess_letter_aux(Word, Guesses, Letter, HintsUsed, HintsUsed, Letter):-
    is_alpha(Letter).

guess_letter_aux(Word, Guesses, Letter, HintsUsed, HintsUsedAux, Result):-
    \+ is_alpha(Letter),
    writeln("Digite uma LETRA"),
    guess_letter(Word, Guesses, HintsUsed, HintsUsedAux, Result).

start_game(Word, Score, EncryptedWord):-
    get_hidden_word(Word, HiddenWord),
    run_game(Word, HiddenWord, [], 5, 0, Score, EncryptedWord).

run_game(Word, HiddenWord, Guesses, 0, HintsUsed, 0, EncryptedWord):-
    show_game_over_message,
    reveal_word(Word), !.

run_game(Word, HiddenWord, Guesses, Lives, HintsUsed, Score, EncryptedWord):-
    all_letters_revealed(HiddenWord),
    get_score(Word, Lives, HintsUsed, Score),
    show_victory_message,
    reveal_word(Word), !.

run_game(Word, HiddenWord, Guesses, Lives, HintsUsed, Score, EncryptedWord):-
    clear_screen,
    show_game_info(Word, HiddenWord, Guesses, Lives, HintsUsed, EncryptedWord),
    guess_letter(Word, Guesses, HintsUsed, HintsUsedAux, Letter),
    reveal_letter(Word, HiddenWord, Letter, HiddenWordAux),
    get_lives(HiddenWord, HiddenWordAux, Lives, LivesAux),
    run_game(Word, HiddenWordAux, [Letter|Guesses], LivesAux, HintsUsedAux, Score, EncryptedWord).

get_lives(HiddenWord, HiddenWordAux, CurrentLives, Lives):-
    HiddenWord == HiddenWordAux ->
        Lives is CurrentLives - 1;
        Lives is CurrentLives.

all_letters_revealed(Word):-
    string_chars(Word, Chars),
    \+ member('_', Chars).

show_game_info(Word, HiddenWord, Guesses, Lives, HintsUsed, EncryptedWord):-
    doll_draw(Lives),
    setup_words,
    word(Word, Theme, _),
    write("Palavra cifrada: "), writeln(EncryptedWord),
    write("Tema: "), writeln(Theme),
    write("Palavra: "), writeln(HiddenWord),
    write("Letras já usadas: "),
    show_guesses(Guesses, GuessesString),
    writeln(GuessesString),
    write("Dicas usadas: "), writeln(HintsUsed).

reveal_word(Word):-
    write("\nA palavra era: "), write(Word),
    write(".\n\n                         [ Pressione ENTER para voltar ]"),
    get_char(_).

get_tip(Word, Guesses, Letter):-
    atom_string(Word, StringWord),
    string_chars(Word, Chars),
    length(Chars, Size),
    random(0, Size, RandomIndex),
    nth0(RandomIndex, Chars, RandomLetter),
    get_tip_aux(Word, RandomLetter, Guesses, Letter).

get_tip_aux(Word, RandomLetter, Guesses, Letter):-
    member(RandomLetter, Guesses),
    get_tip(Word, Guesses, Letter).

get_tip_aux(Word, ' ', Guesses, Letter):-
	get_tip(Word, Guesses, Letter).

get_tip_aux(Word, RandomLetter, Guesses, RandomLetter).

:- initialization(main).

main:-
	intro,
	menu.
