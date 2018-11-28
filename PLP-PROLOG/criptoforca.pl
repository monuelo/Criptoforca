:- use_module(library(apply)).
:- use_module(library(csv)).

setup_words :-
    reconsult('palavras.pl').


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

write_player(Nickname, Score):-
    string_lower(Nickname, NicknameLowerCase),
    assertz(player(NicknameLowerCase, Score)),
    write_player_file.

get_themes(Result):-
    setup_words,
    findall(Theme, word(_, Theme, _), Queries),
    list_to_set(Queries, Result).

get_level(Text, Level):- 
    atom_length(Text, Size),
    (compare(<, Size, 6) -> Level is 1;
    compare(<, Size, 10) -> Level is 2;
    Level is 3).
    
filter_by_theme(Theme, Result):-
    setup_words,
    findall([Text, Theme, Level], word(Text, Theme, Level), Result).

filter_by_level(Level,Result):-
    setup_words,
    findall([Text, Theme, Level], word(Text, Theme, Level), Result).

themed_fast_match:- 
    select_theme(Theme),
    filter_by_theme(Theme, Result),
    get_random_word(Result, RandomWord),
    get_word_text(RandomWord, WordText),
    start_game(WordText, Score).

get_word_text(Word, Text):-
    nth0(0, Word, Text).

leveled_fast_match:-
    select_level(Level),
    filter_by_level(Level, Result),
    get_random_word(Result, RandomWord),
    get_word_text(RandomWord, WordText),
    start_game(WordText, Score).

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

select_menu_option(1) :- show_game_modes.
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
    writeln("                                2  -  Explicacao"),
    writeln("                                3  -  Nova Palavra"),
    writeln("                                4  -  Sair"),
    get_option(Option),
    select_menu_option(Option).
    
show_invalid_option_message :-
    writeln("           Opção inválida... Pressione ENTER para tentar novamente!\n"),
    pause,
    menu.
    
show_game_modes :-
    clear_screen,
    writeln("\n-----------------------------     MODO DE JOGO     -----------------------------\n\n"),
    writeln("                                1  -  Jogo Rápido"),
    writeln("                                2  -  Voltar"),
    get_option(Option),
    select_game_mode(Option).

select_game_mode(1) :- fast_match_mode.
select_game_mode(2) :- menu.
select_game_mode(_) :- show_invalid_option_message.

show_hangman(Lives) :-
	clear_screen,
    writeln("                                 ###############"),
    writeln("                                 #### FORCA ####"),
    writeln("                                 ###############"),
    writeln("                                 #      |      #"),
    
    show_hangman_body(Lives),
    
    writeln("                                 ###############"),
    writeln("                                  /\\         /\\"),
    writeln("                                 /  \\       /  \\ \n").

show_hangman_body(7) :-
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 #             #").

show_hangman_body(6) :-
    writeln("                                 #    ('-')    #"),
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 #             #").

show_hangman_body(5) :-
    writeln("                                 #    ('-')__  #"),
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 #             #").

show_hangman_body(4) :-
    writeln("                                 #  __('-')__  #"),
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 #             #").

show_hangman_body(3) :-
    writeln("                                 #  __('-')__  #"),
    writeln("                                 #      |      #"),
    writeln("                                 #             #"),
    writeln("                                 #             #").

show_hangman_body(2) :-
    writeln("                                 #  __('-')__  #"),
    writeln("                                 #      |      #"),
    writeln("                                 #     /       #"),
    writeln("                                 #             #").

show_hangman_body(1) :-
    writeln("                                 #  __('-')__  #"),
    writeln("                                 #      |      #"),
    writeln("                                 #     / \\     #"),
    writeln("                                 #             #").
    
show_hangman_body(0) :-
    writeln("                                 #      |      #"),
    writeln("                                 #    (-.-)    #"),
    writeln("                                 #     /|\\     #"),
    writeln("                                 #     / \\     #").
    
show_victory_hangman :-
	clear_screen,
    writeln("                                 ###############"),
    writeln("                                 #### FORCA ####"),
    writeln("                                 ###############"),
    writeln("                                 #      |      #"),
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 #             #"),
    writeln("                                 ###############     \\('◡')/"),
    writeln("                                  /\\         /\\         |"),
    writeln("                                 /  \\       /  \\       / \\ \n\n"),
    writeln("YOU WIN!"),
    sleep_3s,
    menu.

show_defeat_hangman :-
	clear_screen,
    writeln("                                 ###############"),
    writeln("                                 #### FORCA ####"),
    writeln("                                 ###############"),
	show_hangman_body(0),
    writeln("                                 ###############"),
    writeln("                                  /\\         /\\"),
    writeln("                                 /  \\       /  \\ \n"),
    writeln("YOU LOSE!"),
    sleep_3s,
    menu.

fast_match_mode :-
    clear_screen,
    writeln("\n-----------------------------     JOGO RÁPIDO     ------------------------------\n\n"),
    writeln("                      Como sua palavra deve ser escolhida?\n"),
    writeln("                              1  -  Por Tema"),
    writeln("                              2  -  Por Dificuldade"),
    writeln("                              3  -  Aleatoriamente"),
    writeln("                              4  -  Voltar"),
    get_option(Option),
    fast_match_mode_aux(Option).

fast_match_mode_aux(1):- themed_fast_match.
fast_match_mode_aux(2):- leveled_fast_match.
fast_match_mode_aux(3):- random_fast_match.
fast_match_mode_aux(_):- show_invalid_option_message.

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
    % get_option

show_rules :- 
    clear_screen,
    writeln("\n--------------------------------     REGRAS     --------------------------------\n\n\n"),
    
    writeln("     O jogo funciona como um jogo da forca comum, porém o jogador terá acesso à uma "),
    writeln("criptografia da palavra a ser adivinhada. O jogador poderá escolher entre 4 niveis  "),
    writeln(" de dificuldade ( Rasgado, Fácil, Médio e Enigma ) os quais farão uso das seguintes    "),
    writeln(" seguintes criptografias:                                                             "),
    writeln(" 1 - Shift         = Transporta a primeira letra para o fim da palavra                "),
    writeln(" 2 - Cesar         = Soma 1 no codigo ASCII de cada letra da palavra                  "),
    writeln(" 3 - NoThenYes     = Realiza Cesar em letras alternadas                               "),
    writeln(" 4 - ASCII         = Mostra o codigo ASCII de cada letra da palavra                   "),
    writeln(" 5 - Fibonacci     = Incrementa ao código ascii da k-ésima letra da palavra o k-esimo   "),
    writeln("    valor da sequencia de Fibonacci, para uma palavra de n letras e para 0 < k <= n   "),
    writeln(" 6 - Complementary  = substitui a cada letra por sua complementar no alfabeto.          "),
    writeln("    Por exemplo: a -> z; b -> y; c -> x; etc...                                        "),
    writeln(" 7 - Cryptomix     = realiza a seguinte sequencia de criptografias: shift, cesar,      "),
    writeln("    complementary e fibonacci                                                         "),
    writeln(" 8 - Alternate     = soma o codigo ascii de cada letra a cada valor da sequencia      "),
    writeln("    alternada a(n); a(n) = 2*n*(-1)^n                                                 "),   
    writeln("                         [ Pressione ENTER para voltar ]\n\n\n"),
    pause,
    menu.

show_victory_message :-
    clear_screen,
    writeln("                     Parabéns, você acaba de salvar uma vida!\n\n"),
    show_victory_hangman.

show_game_over_message :-
    clear_screen,
    writeln("                       É realmente uma pena, fim de jogo...\n\n"),
    show_defeat_hangman.



get_word_data :-
    clear_screen,
    writeln("\n---------------------------     CIFRAR PALAVRA     --------------------------\n\n\n"),
    write("          Informe a nova palavra: "),
    read(Word),
    writeln(" Palavra Cifrada: "),
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
    writeln("Digite uma letra ou ç para dica: "),
    read(Letter),
    guess_letter_aux(Word, Guesses, Letter, HintsUsed, HintsUsedAux, Result).

guess_letter_aux(Word, Guesses, 'ç', HintsUsed, HintsUsedAux, Tip):-
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
    writeln("Uma letra, meu anjo..."),
    guess_letter(Word, Guesses, HintsUsed, HintsUsedAux, Result).

start_game(Word, Score):-
    get_hidden_word(Word, HiddenWord),
    run_game(Word, HiddenWord, [], 7, 0, Score).

run_game(Word, HiddenWord, Guesses, 0, HintsUsed, 0):-
    show_game_over_message,
    reveal_word(Word), !.

run_game(Word, HiddenWord, Guesses, Lives, HintsUsed, Score):-
    all_letters_revealed(HiddenWord),
    get_score(Word, Lives, HintsUsed, Score),
    show_victory_message,
    reveal_word(Word), !.

run_game(Word, HiddenWord, Guesses, Lives, HintsUsed, Score):-
    clear_screen,
    show_game_info(Word, HiddenWord, Guesses, Lives, HintsUsed),
    guess_letter(Word, Guesses, HintsUsed, HintsUsedAux, Letter),
    reveal_letter(Word, HiddenWord, Letter, HiddenWordAux),
    get_lives(HiddenWord, HiddenWordAux, Lives, LivesAux),
    run_game(Word, HiddenWordAux, [Letter|Guesses], LivesAux, HintsUsedAux, Score).

get_lives(HiddenWord, HiddenWordAux, CurrentLives, Lives):-
    HiddenWord == HiddenWordAux -> 
        Lives is CurrentLives - 1;
        Lives is CurrentLives.

all_letters_revealed(Word):-
    string_chars(Word, Chars),
    \+ member('_', Chars).

show_game_info(Word, HiddenWord, Guesses, Lives, HintsUsed):-
    show_hangman(Lives),
    setup_words,
    word(Word, Theme, _),
    write("Palavra que deveria ser cifrada: "), writeln(Word),
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