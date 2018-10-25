import System.IO
import Data.Char
import Data.List
import Data.Ord
import Data.Time.Clock.POSIX
import qualified System.Process
import Control.Monad


------------- CRIPTOFUNCTIONS -------------

--SHIFT CRYPTOGRAPHY -- level: rasgado
shift :: [Char] -> [Char]
shift (x:xs) = xs ++ [x]

--"NO THEN YES" CRYPTOGRAPHY -- level: rasgado
noThenYes :: Int -> [Char] -> [Char]   --
noThenYes n [] = []
noThenYes n (x:xs) = [chr(ord(x)+n)] ++ noThenYes(mod(n+1)(2))(xs)

--CESAR CRYPTOGRAPHY -- level: facil
cesar1 :: [Char] -> [Char]
cesar1 [] = []
cesar1 (x:xs) = [chr(ord(x)+1)] ++ cesar1(xs)

--ASCII CRYPTOGRAPHY -- level: facil
ascii :: [Char] -> String
ascii [] = ""
ascii (x:xs) = show(ord(x)) ++ ascii (xs)

--FIBONACCI CRYPTOGRAPHY -- level: medio
fibonacciSequence :: Int -> Int
fibonacciSequence 0 = 0
fibonacciSequence 1 = 1
fibonacciSequence n = fibonacciSequence(n-1) + fibonacciSequence(n-2)

fibonacciCripto :: Int -> [Char] -> [Char]
fibonacciCripto n [] = []
fibonacciCripto n (x:xs) = [chr( mod(ord(x) + fibonacciSequence(n)) 128)] ++ fibonacciCripto (n+1)(xs)

--COMPLEMENTARY CRYPTOGRAPHY -- level: medio
complementary :: [Char] -> [Char]
complementary [] = []
complementary (x:xs) = [chr(ord('a') + ord('z') - ord(x))] ++ complementary(xs)

--CRYPTOMIX CRYPTOGRAPHY  -- level: enigma
cryptomix :: [Char] -> [Char]
cryptomix (x) = fibonacciCripto 1 (complementary (cesar1(shift (x))))

--ALTERNATE CRYPTOGRAPHY  -- level: enigma
alternate :: Int -> [Char] -> [Char]
alternate n [] = []
alternate n (x:xs) = [chr(ord(x) + n*((-1)^n))] ++ alternate(n+1)(xs)

encryptWord :: Int -> Main.Word -> String
encryptWord 1 word = shift (text word)

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

selectHintOption :: Int -> Main.Word -> IO()
selectHintOption 1 word = revealCategory (theme word) 
-- selectHintOption 2 = getHint
-- selectHintOption 3 = revealCategory
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

    if (level < 1 || level > 3) 
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


fastMatch :: Int -> IO()
fastMatch level = do
    words <- setUpWords
    randomWord <- getRandomWord words
    startGame level randomWord
    
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
    putStrLn $ "Palavra: " ++ hiddenWord
    putStrLn $ "Letras já usadas: " ++ showGuesses guesses

    (letter, hintsUsed') <- guessLetter hintsUsed originalWord guesses
    let hiddenWord' = revealLetter letter (text originalWord) hiddenWord
    
    let guesses' = if letter == '1' then do guesses else guesses ++ [letter]
    let lives' = if letter == '1' then do lives else getLives hiddenWord hiddenWord' lives

    if hiddenWord' == text originalWord then do
        showVictoryMessage
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
    putStrLn "                         [ Pressione ENTER para voltar ]\n\n"
    _ <- getLine
    return ()

showVictoryMessage :: IO()
showVictoryMessage = do
    clearScreen
    putStrLn "                     \n Hmmm... Preciso melhorar meus algoritmos!\n\n"
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