{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1)

maxVal :: Integer
maxVal = 55

listOfFact :: [(Integer, Integer)]
listOfFact = [(i, fact i) | (i, _) <- zip [1..maxVal] [1..maxVal]]

sumRange :: Integer -> Integer
sumRange n = sum [j | (i, j) <- listOfFact, i <= n]

stoi :: String -> Int
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + (ord c - ord '0')

main :: IO ()
main = do
  [n] <- map (stoi . T.unpack) . T.words <$> I.getLine
  putStrLn (show (sumRange (toInteger n)))