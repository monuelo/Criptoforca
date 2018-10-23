import System.IO
import Control.Exception
import Data.Char

data State = State 
  { guessesLeft :: Int
  , guessedChars :: String
  , targetWord :: String }

-- draws the man to screen
drawMan :: State -> IO ()
drawMan gs = do
  case guessesLeft gs of
    6 -> guy0;
    5 -> guy1;
    4 -> guy2;
    3 -> guy3;
    2 -> guy4;
    1 -> guy5;
    0 -> guy6;

-- draws the "_"-masked word with the new character added, or same if no match
drawWord :: State -> IO ()
drawWord gs = do 
  putStrLn ("   " ++ map mask (targetWord gs))
  where
    mask c 
      | c == ' ' = ' '
      | elem c (guessedChars gs) = c -- if c is in the characters that have been guessed
      | otherwise = '_' -- otherwise, hide it


getGuess :: String -> IO Char
getGuess oldGuess = do
  putStrLn("What is your next guess?")
  input <- getLine

  case input of
    -- guess was empty, ask again
    [] -> getGuess oldGuess
    -- get the first character only, in case of string input
    (c : tail) -> return c

getNextState :: State -> IO State
getNextState oldState = do

  -- process the guess
  c <- getGuess (guessedChars oldState)

  if (elem c (targetWord oldState))
    then do
      return (State 
        ((guessesLeft oldState)) 
        ((guessedChars oldState) ++ [c]) 
        (targetWord oldState))
    else do
      return (State 
        ((guessesLeft oldState) - 1) 
        ((guessedChars oldState) ++ [c]) 
        (targetWord oldState))

-- loop to hold player in limbo until new game
endGame :: IO ()
endGame = do
  putStrLn "Game is over. Type 'restart' to play again."
  ln <- getLine
  if ln == "restart"
    then main
    else endGame

-- runs the game's functionality in a loop until the end
game :: State -> IO ()
game gs = do
  drawMan gs
  putStrLn("")
  drawWord gs
  putStrLn("")

  if (guessesLeft gs) == 0
    then do
      putStrLn("You've lost! The word you were guessing is " ++ show (targetWord gs) ++ "\n")
      endGame
    else if all (\x -> elem x (guessedChars gs)) (targetWord gs)
      then do
        putStrLn("You won in " ++ show (length (guessedChars gs) - 1) ++ " guesses!\n")
        endGame
      else do
        nextState <- getNextState gs
        game nextState

-- helper to set initial word-to-be-guessed
getWord :: IO String
getWord = do
  hFlush stdout
  word <- withEcho False getLine
  return word

-- helper to handle rerouting input
withEcho :: Bool -> IO a -> IO a
withEcho echo action = do
  old <- hGetEcho stdin
  bracket_ (hSetEcho stdin echo) (hSetEcho stdin old) action

-- create initial game state
initialize :: IO State
initialize = do
  putStrLn "What word would you like your friend to guess?"
  word <- getWord
  let lowerWord = map toLower word -- for consistency sake
  return (State 6 " " lowerWord)
  -- init with 6 guesses remaining

main :: IO ()
main = do
    putStrLn "\nWelcome to Haskell Hangman!"

    
    gs <- initialize  -- will initialize gamestate on start
    game gs -- begin the game with fresh state

------------- HANGMAN IMAGES

guy0 :: IO ()
guy0 = do
  putStrLn("      _______")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("    _|_")
  putStrLn("   |   |______")
  putStrLn("   |__________|")

guy1 :: IO ()
guy1 = do
  putStrLn("      _______")
  putStrLn("     |       |")
  putStrLn("     |      (_)")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("    _|_")
  putStrLn("   |   |______")
  putStrLn("   |__________|")

guy2 :: IO ()
guy2 = do
  putStrLn("      _______")
  putStrLn("     |       |")
  putStrLn("     |      (_)")
  putStrLn("     |       |")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("    _|_")
  putStrLn("   |   |______")
  putStrLn("   |__________|")

guy3 :: IO ()
guy3 = do
  putStrLn("      _______")
  putStrLn("     |       |")
  putStrLn("     |      (_)")
  putStrLn("     |      /|")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("    _|_")
  putStrLn("   |   |______")
  putStrLn("   |__________|")

guy4 :: IO ()
guy4 = do
  putStrLn("      _______")
  putStrLn("     |       |")
  putStrLn("     |      (_)")
  putStrLn("     |      /|\\")
  putStrLn("     |")
  putStrLn("     |")
  putStrLn("    _|_")
  putStrLn("   |   |______")
  putStrLn("   |__________|")

guy5 :: IO ()
guy5 = do
  putStrLn("      _______")
  putStrLn("     |       |")
  putStrLn("     |      (_)")
  putStrLn("     |      /|\\")
  putStrLn("     |      /")
  putStrLn("     |")
  putStrLn("    _|_")
  putStrLn("   |   |______")
  putStrLn("   |__________|")

guy6 :: IO ()
guy6 = do
  putStrLn("      _______")
  putStrLn("     |       |")
  putStrLn("     |      (_)")
  putStrLn("     |      /|\\")
  putStrLn("     |      / \\")
  putStrLn("     |")
  putStrLn("    _|_")
  putStrLn("   |   |______")
  putStrLn("   |__________|")
