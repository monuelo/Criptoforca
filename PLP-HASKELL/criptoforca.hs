import System.IO
import Data.Char
import Data.List
import Data.Ord


Menu :: IO()
Menu = do
    clearScreen
    putStrLn "    1- Rasgado "
    putStrLn "    2- Facil "
    putStrLn "    3- Medio "
    putStrLn "    4- Enigma"
    clearScreen


shiftStr :: Int -> String -> String
shiftStr n = map shiftChar
  where
    alphabet = ['a'..'z']
    alphaLoop = cycle alphabet
    shiftChar c = head
        $ drop (length alphabet + n)
        $ dropWhile (/= c) alphaLoop
