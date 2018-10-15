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
