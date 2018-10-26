import System.IO
import Data.Char
import Data.List
import Data.Ord
import Data.Time.Clock.POSIX
import qualified System.Process
import Control.Monad


------------- CRIPTOFUNCTIONS -------------

--------SHIFT CRYPTOGRAPHY -- level 1: rasgado
----DESCRICAO:
--Desloca a primeira letra para a ultima posicao
shift :: [Char] -> [Char]
shift (x:xs) = xs ++ [x]

--------"NO THEN YES" CRYPTOGRAPHY -- level 1: rasgado
----DESCRICAO:
--utiliza a criptografia cesar1 em letras alternadas
noThenYes :: Int -> [Char] -> [Char]
noThenYes n [] = []
noThenYes 0 (x:xs) = [x] ++ noThenYes (1)(xs)
noThenYes 1 (x:xs) = cesar1 ([x]) ++ noThenYes (0)(xs)

--------CESAR CRYPTOGRAPHY -- level 2: facil
----DESCRICAO:
--troca cada letra por seu caracter sucessor na tabela ascii
cesar1 :: [Char] -> [Char]
cesar1 [] = []
cesar1 (x:xs) = [chr(ord(x)+1)] ++ cesar1(xs)

--------ASCII CRYPTOGRAPHY -- level 2: facil
----DESCRICAO:
--substitui cada letra por seu codigo ascii
ascii :: [Char] -> [Char]
ascii [] = ""
ascii (x:xs) = show(ord(x)) ++ ascii (xs)

--------FIBONACCI CRYPTOGRAPHY -- level 3: medio
----DESCRICAO:
--incrementa ao codigo ascii da k-esima letra da palavra o k-esimo valor da sequencia de Fibonacci, para uma palavra de n letras e para 0 < k <= n
fibonacciSequence :: Int -> Int
fibonacciSequence 0 = 0
fibonacciSequence 1 = 1
fibonacciSequence n = fibonacciSequence(n-1) + fibonacciSequence(n-2)

fibonacciCripto :: Int -> [Char] -> [Char]
fibonacciCripto n [] = []
fibonacciCripto n (x:xs) = [chr( (mod(ord(x) + fibonacciSequence(n)) 96) + 32)] ++ fibonacciCripto (n+1)(xs)

--------COMPLEMENTARY CRYPTOGRAPHY -- level 3: medio
----DESCRICAO:
--substitui a cada letra por sua complementar no alfabeto. Por exemplo: a -> z; b -> y; c -> x etc
complementary :: [Char] -> [Char]
complementary [] = []
complementary (x:xs) = [chr(ord('A') + ord('Z') - ord(x))] ++ complementary(xs)

--------CRYPTOMIX CRYPTOGRAPHY  -- level 4: enigma
----DESCRICAO:
--realiza a seguinte sequencia de criptografias: shift, cesar, complementary e fibonacci
cryptomix :: [Char] -> [Char]
cryptomix (x) = fibonacciCripto 1 (complementary (cesar1(shift (x))))

--------ALTERNATE CRYPTOGRAPHY  -- level 4: enigma
----DESCRICAO:
--soma o codigo ascii de cada letra a cada valor da sequencia alternada a(n); a(n) = 2*n*(-1)^n
alternate :: Int -> [Char] -> [Char]
alternate n [] = []
alternate n (x:xs) = [chr(ord(x) + 2*n*((-1)^n))] ++ alternate(n+1)(xs)

encryptWord :: Int -> Main.Word -> String
encryptWord 1 word = shift (text word)
encryptWord 2 word = noThenYes 0(text word)
encryptWord 3 word = cesar1 (text word)
encryptWord 4 word = ascii (text word)
encryptWord 5 word = fibonacciCripto 1 (text word)
encryptWord 6 word = complementary (text word)
encryptWord 7 word = cryptomix (text word)
encryptWord 8 word = alternate 1(text word)

data Word = Word { 
    text :: String,
    theme :: String
} deriving (Eq, Show)

setUpWords :: IO [Main.Word]
setUpWords = do
    words <- readWords
    return $ createWordList words
    where readWords = do
              words <- openFile "./words.csv" ReadMode
              contents <- hGetContents words
              return $ lines contents
          createWordList [] = []
          createWordList (head:tail) = [createWord $ splitOnComma head] ++ createWordList tail
              where createWord (text:theme:_) = Word text theme

splitOnComma :: String -> [String]
splitOnComma s = splitOnComma' s ""
    where
        splitOnComma' [] w = [w]
        splitOnComma' (',':tail) w = [w] ++ splitOnComma' tail ""
        splitOnComma' (head:tail) w = splitOnComma' tail (w ++ [head])

clearScreen :: IO()
clearScreen = do
    _ <- System.Process.system "clear"
    return ()

sleep :: IO()
sleep = do
    _ <- System.Process.system "sleep 2s"
    return ()

pause :: IO ()
pause = do
    x <- getChar
    putStrLn ""

showOpening :: IO()
showOpening = do
    clearScreen
    putStrLn "      ____________..___________                                                                "
    putStrLn "     | .___________))__________|                                                               "
    putStrLn "     | | / /       ||                                                                          "
    putStrLn "     | |/ /        ||              _____      _       _         __                             "
    putStrLn "     | | /         ||.-''.        / ____|    (_)     | |       / _|                            "
    putStrLn "     | |/          |/  _  \\      | |     _ __ _ _ __ | |_ ___ | |_ ___  _ __ ___ __ _         "
    putStrLn "     | |           ||  `/,|      | |    | '__| | '_ \\| __/ _ \\|  _/ _ \\| '__/ __/ _` |      "
    putStrLn "     | |           (\\\\`_.'       | |____| |  | | |_) | || (_) | || (_) | | | (_| (_| |       "
    putStrLn "     | |          .-`--'.         \\_____|_|  |_| .__/ \\__\\___/|_| \\___/|_|  \\___\\__,_|   "
    putStrLn "     | |         /Y . . Y\\                   | |                                              "
    putStrLn "     | |        // |   | \\\\                  |_|                                             "
    putStrLn "     | |       //  | . |  \\\\                                                                 "
    putStrLn "     | |      ')   | _ |   (`                                                                  "
    putStrLn "     | |           || ||                                                                       "
    putStrLn "     | |           || ||                              OFERECIMENTO: PLP@UFCG                   "
    putStrLn "     | |           || ||                                                                       "
    putStrLn "     | |           || ||                                                                       "
    putStrLn "     | |          / | | \\                                                                     "
    putStrLn "     | |          `-' `-'                                                                      "
    putStrLn "     |_|                                                                                       "
    putStrLn "                                        Pressione [Enter] para continuar...                    "
    _ <- getLine
    return()

showMenu :: IO()
showMenu = do
    clearScreen
    putStrLn "\n---------------------------------     MENU     ---------------------------------\n\n"
    putStrLn "                                1  -  Jogar"
    putStrLn "                                2  -  Regras"
    putStrLn "                                3  -  Sair"
    option <- getOption
    selectMenuOption option
    clearScreen
    when (not $ option == 3) $ do clearScreen; showMenu
    
showHints :: Main.Word -> [Char] -> IO()
showHints word guesses = do
    clearScreen
    putStrLn "\n---------------------------------     DICAS     ---------------------------------\n\n"
    putStrLn "                                1  -  Revelar Categoria"
    putStrLn "                                2  -  Revelar uma Letra"
    putStrLn "                                3  -  Ajuda dos universitários"
    putStrLn "                                4  -  Revelar quantidade de vogais"
    option <- getOption
    selectHintOption option word

-- Hints

vowels = ['A','E','I','O','U', 'a','e','i','o','u']
isVowel x = if elem x vowels then True else False

countNumVowels :: Int -> [Char] -> Int
countNumVowels n [] = n
countNumVowels n (x:xs) = do
    if isVowel x then do
        countNumVowels (n+1) (xs)
    else
        countNumVowels n xs

numVowels :: [Char] -> IO()
numVowels word = do
    let qnt = countNumVowels 0 word
    putStrLn $ "\n                           O número de vogais é: " ++ (show qnt)
    putStr "\n                         [ Pressione ENTER para voltar ]"
    _ <- getLine
    return()

revealCategory :: String -> IO()
revealCategory word = do
    putStrLn $ "\n                           A categoria é: " ++ word
    putStr "\n                         [ Pressione ENTER para voltar ]"
    _ <- getLine
    return()

undergradHelp :: String -> IO()
undergradHelp word = do
    currTimestamp <- getCurrentTimestamp
    let rand = currTimestamp `mod` (10)
    let phrase = if rand < 6 then do "Hmmm... Acho que a palavra é... " ++ word else "Cara, sinceramente, não faço ideia..."
    putStrLn $ "\n                  Os Universitários dizem: " ++ phrase
    putStr "\n                         [ Pressione ENTER para voltar ]"
    _ <- getLine
    return()


selectHintOption :: Int -> Main.Word -> IO()
selectHintOption 1 word = revealCategory (theme word) 
-- selectHintOption 2 = getHint
selectHintOption 3 word = undergradHelp (text word)
selectHintOption 4 word = numVowels (text word)
selectHintOption n word = showInvalidOptionMessage

getOption :: IO Int
getOption = do
    putStr "\n\n                    Informe o número da opção desejada: "
    option <- getLine
    return $ read option

selectMenuOption :: Int -> IO()
selectMenuOption 1 = selectLevel
selectMenuOption 2 = showRules
selectMenuOption 3 = quit
selectMenuOption n = showInvalidOptionMessage

showInvalidOptionMessage :: IO()
showInvalidOptionMessage = do
    putStrLn "           Opção inválida... Pressione ENTER para tentar novamente!\n"
    pause

selectLevel :: IO()
selectLevel = do
    showLevels
    level <- getOption

    if (level < 1 || level > 4) 
        then do
            showInvalidOptionMessage
            selectLevel
    else do
        fastMatch level

showLevels :: IO()
showLevels = do
    clearScreen
    putStrLn "\n------------------------     SELECIONAR DIFICULDADE     ------------------------\n\n";
    putStrLn "                              1  -  Rasgado"
    putStrLn "                              2  -  Facil"
    putStrLn "                              3  -  Medio"
    putStrLn "                              4  -  Enigma\n\n"

criptoByLevel :: Int -> IO Int
criptoByLevel 1 = randomChoice 1 2
criptoByLevel 2 = randomChoice 3 4
criptoByLevel 3 = randomChoice 5 6
criptoByLevel 4 = randomChoice 7 8

randomChoice :: Int -> Int -> IO Int
randomChoice a b = do
    currTimestamp <- getCurrentTimestamp
    let rand = currTimestamp `mod` 2
    let choice = if (rand == 1) then do a else b
    return(choice)

fastMatch :: Int -> IO()
fastMatch level = do
    words <- setUpWords
    randomWord <- getRandomWord words
    cripto <- criptoByLevel level
    startGame (cripto) randomWord
    
getCurrentTimestamp :: IO Int
getCurrentTimestamp = do
    currentTime <- getPOSIXTime
    let currTimestamp = floor $ currentTime * 100000
    return currTimestamp

getRandomWord  :: [Main.Word] -> IO Main.Word
getRandomWord words = do
    currTimestamp <- getCurrentTimestamp
    let index = currTimestamp `mod` (length words)
    let word = words !! index
    return word
    
getRandomOrderWords' :: [Main.Word] -> [Main.Word] -> IO [Main.Word]
getRandomOrderWords' randomOrderWords currentLevelWords = do
    if (length randomOrderWords) < (length currentLevelWords) then do 
        randomOrderWord <- getRandomOrderWord randomOrderWords currentLevelWords
        getRandomOrderWords' (randomOrderWords++[randomOrderWord]) currentLevelWords
    else
        return randomOrderWords

getRandomOrderWord :: [Main.Word] -> [Main.Word] -> IO Main.Word
getRandomOrderWord randomOrderWords currentLevelWords = do 
    word <- getRandomWord currentLevelWords
    if word `elem` randomOrderWords then
        getRandomOrderWord randomOrderWords currentLevelWords
    else
        return word
    
startGame :: Int -> Main.Word -> IO()
startGame level word = do
    let hiddenWord = getHiddenWord $ text word
    (lives, hintsUsed) <- runGame level word hiddenWord [] 5 0
    return()

runGame :: Int -> Main.Word -> String -> [Char] -> Int -> Int -> IO (Int, Int)
runGame level originalWord hiddenWord guesses lives hintsUsed = do
    dollDraw lives
    putStrLn $ "Palavra Cifrada: " ++ encryptWord level originalWord
    putStrLn $ "\nPalavra: " ++ hiddenWord
    putStrLn $ "Letras já usadas: " ++ showGuesses guesses
    putStrLn $ "Erros Restantes: " ++ (show lives)
    (letter, hintsUsed') <- guessLetter hintsUsed originalWord guesses
    let hiddenWord' = revealLetter letter (text originalWord) hiddenWord
    
    let guesses' = if letter == '1' then do guesses else guesses ++ [letter]
    let lives' = if letter == '1' then do lives else getLives hiddenWord hiddenWord' lives

    if hiddenWord' == text originalWord then do
        showVictoryMessage level
        revealWord originalWord
        return (lives', hintsUsed')
    else if lives' > 0 then do
        runGame level originalWord hiddenWord' guesses' lives' hintsUsed'
    else do
        showGameOverMessage
        revealWord originalWord
        return (0, hintsUsed')

getLives :: String -> String -> Int -> Int
getLives word word' currentLives
    | word == word' = currentLives - 1
    | otherwise = currentLives

getHiddenWord :: String -> String
getHiddenWord [] = []
getHiddenWord (' ':tail) = [' '] ++ getHiddenWord tail
getHiddenWord (head:tail) = ['_'] ++ getHiddenWord tail

showGuesses :: String -> String
showGuesses [] = []
showGuesses (head:[]) = [head]
showGuesses (head:tail) = [head] ++ [' '] ++ showGuesses tail

revealLetter :: Char -> String -> String -> String
revealLetter letter [] [] = []
revealLetter letter (head:tail) (head':tail')
    | letter == head = [letter] ++ revealLetter letter tail tail'
    | otherwise = [head'] ++ revealLetter letter tail tail'

getLetter :: IO Char
getLetter = do
    letter <- getChar
    _ <- getChar
    return (toUpper letter)
    
toUpper' :: String -> String
toUpper' s = map toUpper s

guessLetter :: Int -> Main.Word -> [Char] -> IO (Char, Int)
guessLetter hintsUsed word guesses = do
    putStr "\nDigite uma letra ou pressione [1] para dica: "
    letter <- getLetter
    (letter, hintsUsed') <- guessLetter' hintsUsed word guesses letter
    return (letter, hintsUsed')

guessLetter' :: Int -> Main.Word -> [Char] -> Char -> IO (Char, Int)
guessLetter' hintsUsed word guesses letter 
    | letter == '1' = do
        showHints word guesses 
        return (letter, hintsUsed)
    | isLetter letter && not(letter `elem` guesses) = do 
        return (letter, hintsUsed)
    | not (isLetter letter) = do
        putStrLn "Hmmm... Acho que isto não é uma letra..."
        guessLetter hintsUsed word guesses
    | otherwise = do
        putStrLn "Amnésia, né? Você já usou isso aí!"
        guessLetter hintsUsed word guesses

dollDraw :: Int -> IO()
dollDraw lives = do
    clearScreen
    dollDrawBody lives

dollDrawBody :: Int -> IO()
dollDrawBody 5 = do
    putStrLn("\n\n      _______")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("    _|_")
    putStrLn("   |   |______")
    putStrLn("   |__________|\n\n")

dollDrawBody 4 = do
    putStrLn("\n\n      _______")
    putStrLn("     |       |")
    putStrLn("     |      (_)")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("    _|_")
    putStrLn("   |   |______")
    putStrLn("   |__________|\n\n")

dollDrawBody 3 = do
    putStrLn("\n\n      _______")
    putStrLn("     |       |")
    putStrLn("     |      (_)")
    putStrLn("     |      /|")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("    _|_")
    putStrLn("   |   |______")
    putStrLn("   |__________|\n\n")

dollDrawBody 2 = do
    putStrLn("\n\n      _______")
    putStrLn("     |       |")
    putStrLn("     |      (_)")
    putStrLn("     |      /|\\")
    putStrLn("     |")
    putStrLn("     |")
    putStrLn("    _|_")
    putStrLn("   |   |______")
    putStrLn("   |__________|\n\n")

dollDrawBody 1 = do
    putStrLn("\n\n      _______")
    putStrLn("     |       |")
    putStrLn("     |      (_)")
    putStrLn("     |      /|\\")
    putStrLn("     |      /")
    putStrLn("     |")
    putStrLn("    _|_")
    putStrLn("   |   |______")
    putStrLn("   |__________|\n\n")
    
drawVictoryDoll :: IO()
drawVictoryDoll = do
    putStrLn("\n\n      _______")
    putStrLn("     | *    *     *")
    putStrLn("     |   *   *")
    putStrLn("     |  *      *")
    putStrLn("     |      *      *")
    putStrLn("     |   \\(*-*)/")
    putStrLn("    _|_     | ")
    putStrLn("   |   |___/_\\_")
    putStrLn("   |__________|\n\n")

drawDefeatDoll :: IO()
drawDefeatDoll = do
    putStrLn("\n\n      _______")
    putStrLn("     |       |")
    putStrLn("     |     (x_x)")
    putStrLn("     |      /|\\")
    putStrLn("     |      / \\")
    putStrLn("     |")
    putStrLn("    _|_")
    putStrLn("   |   |______")
    putStrLn("   |__________|\n\n")

showRules :: IO()
showRules = do 
    clearScreen
    putStrLn "\n--------------------------------     REGRAS     --------------------------------\n\n"
    putStrLn "     O jogo funciona como um jogo da forca comum, porém o jogador terá acesso à uma   "
    putStrLn " criptografia da palavra a ser adivinhada. O jogador poderá escolher entre 4 niveis   "    
    putStrLn " de dificuldade ( Rasgado, Fácil, Médio e Enigma ) os quais farão uso das seguintes   "
    putStrLn " seguintes criptografias:                                                           \n"
    putStrLn " 1 - Shift         = Transporta a primeira letra para o fim da palavra                \n"
    putStrLn " 2 - Cesar         = Soma 1 no codigo ASCII de cada letra da palavra                  \n"
    putStrLn " 3 - NoThenYes     = Realiza Cesar em letras alternadas                               \n"
    putStrLn " 4 - ASCII         = Mostra o codigo ASCII de cada letra da palavra                   \n"
    putStrLn " 5 - Fibonacci     = Incrementa ao código ascii da k-ésima letra da palavra o k-esimo   "
    putStrLn "    valor da sequencia de Fibonacci, para uma palavra de n letras e para 0 < k <= n   \n"
    putStrLn " 6 - Complementar  = substitui a cada letra por sua complementar no alfabeto.           "
    putStrLn "    Por exemplo: a -> z; b -> y; c -> x etc                                           \n"
    putStrLn " 7 - Cryptomix     = realiza a seguinte sequencia de criptografias: shift, cesar,       "
    putStrLn "    complementary e fibonacci                                                         \n"
    putStrLn " 8 - Alternate     = soma o codigo ascii de cada letra a cada valor da sequencia        "
    putStrLn "    alternada a(n); a(n) = 2*n*(-1)^n                                                 \n"
    putStrLn "\n\n                         [ Pressione ENTER para voltar ]\n\n                      \n"
    _ <- getLine
    return ()

showVictoryMessage :: Int -> IO()
showVictoryMessage n = do
    clearScreen
    if (n == 7 || n == 8) then do
        putStrLn "                     \n Olha Só!!! Temos um Turing Aqui! :o \n"
        System.Process.system "display turing.jpg"
        putStrLn":------------------------/hmdmmmmmmmmmmmmmmNmmmmddhddmmm+------------:"
        putStrLn":-----------------------:dmdmmdhyssssssssooooosyyhddmmmddo:----------:"
        putStrLn":-----------------------hmdh+/:---------::::::ohddddmmmmmmy:---------:"
        putStrLn":----------------------/Nm+-----------::::::::/sdmmmmmNNNNms--------::"
        putStrLn":----------------------:m+----------:::::::://+sdmmNmNNNNNNd--------::"
        putStrLn":-----------------------+---------:::::::////+osyhdmmNNNNNNd-------:::"
        putStrLn"::---------------------:++/:::::/+oooooo+++++++osyyddddmmmmy------::::"
        putStrLn"::-----------:::::::::::ohhho:/odmmmmdddhyso++++oossssydmmm+------::::"
        putStrLn"::------------:::::::::::ooso::+yhhyhhddhysso++++ooo+/oosyo-------::::"
        putStrLn"::------------::::::::::::::::////////++++/++++++ooo+ss++o+--------:::"
        putStrLn"::------------::::::::::::::///////::::////+++++oo+/sys+++/--------:::"
        putStrLn"::------------::::::::::::/shhyo+////////++ooooooo+/++oo+:---------:::"
        putStrLn":-------------:::::::::::::/oooo+//++++++ooooooooo+//+o/-----------:::"
        putStrLn":---------------::::::::::///++oooo++oooooooooooooooos:------------:::"
        putStrLn":----------------::::::::/o+osyyyhhhysoooooooooossshhs-------------:::"
        putStrLn":----------------::::::::::/oyhysoosyssssoooosssyyyssys:-----------:::"
        putStrLn":-------------------:::::::::///++ossssssssssyyhhysoosdh/----------:::"
        putStrLn":---------------------::::/+ooosssyyyhhhhhhhdddhyoo+/hddho/::-----::::"
        putStrLn":::::::::::::::::::::::::::/+syhddmmmmmmNNNmmdysoo++hdddddhyo+//::::/:"
    else
        drawVictoryDoll

showGameOverMessage :: IO()
showGameOverMessage = do
    clearScreen
    putStrLn "                       \n Parece que essa cifra é forte demais pra você, né? HAHA...\n\n"
    drawDefeatDoll

revealWord :: Main.Word -> IO()
revealWord word = do
    putStrLn $ "\nA palavra era: "++ (text word) ++".\n\n"
    putStr "                         [ Pressione ENTER para voltar ]"
    _ <- getLine
    return ()
    
getSpaces :: Int -> String
getSpaces 0 = ""
getSpaces n = " " ++ getSpaces (n - 1)

getLengthSpacing :: Int -> Int -> String
getLengthSpacing length scoreLength = do
    if (scoreLength > 2) then getSpaces (length - (scoreLength - 2)) else getSpaces length

quit :: IO()
quit = do
    clearScreen
    putStrLn "\n-----------------------------     #$&!CRIPTOForca#$&!     -----------------------------\n\n"
    putStrLn "\n\n                                                                                         "
    putStrLn "            .oPYo.        o          o          d'b                                        "    
    putStrLn "            8    8                   8          8                                          "
    putStrLn "            8      oPYo. o8 .oPYo.  o8P .oPYo. o8P  .oPYo. oPYo. .oPYo. .oPYo.             "
    putStrLn "            8      8  `'  8 8    8   8  8    8  8   8    8 8  `' 8    ' .oooo8             "
    putStrLn "            8    8 8      8 8    8   8  8    8  8   8    8 8     8    . 8    8             "
    putStrLn "            `YooP' 8      8 8YooP'   8  `YooP'  8   `YooP' 8     `YooP' `YooP8             "
    putStrLn "            :.....:..:::::..8 ....:::..::.....::..:::.....:..:::::.....::.....:            "
    putStrLn "            ::::::::::::::::8 :::::::::::::::::::::::::::::::::::::::::::::::::            "
    putStrLn "            ::::::::::::::::..:::::::::::::::::::::::::::::::::::::::::::::::::            "    
    putStrLn "\n\n                               - * - UM OFERECIMENTO - * -                              "
    putStrLn "\n\n                     [PLP@UFCG] [Computação@UFCG] [Eles@Computação]                     "
    sleep

main :: IO()
main = do
    hSetBuffering stdin NoBuffering
    hSetBuffering stdout NoBuffering
    showOpening
    showMenu
