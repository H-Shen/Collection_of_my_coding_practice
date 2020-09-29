-- https://www.hackerrank.com/challenges/pascals-triangle/problem

-- Enter your code here. Read input from STDIN. Print output to STDOUT

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import Data.List (sortBy)
import qualified Data.Text as T
import qualified Data.Text.IO as I

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1)

listOfFact :: [Integer]
listOfFact = [fact i | i <- [0..12]]

f :: Int -> Int -> Integer
f n r = (listOfFact!!n) `div` ( listOfFact!!r * listOfFact!!(n - r) )

g :: Int -> [Integer]
g n = [f n i | i <- [0..n]]

printIntArray :: [Integer] -> IO()
printIntArray [] = return()
printIntArray [m] = putStrLn (show m)
printIntArray (x : xs) = do
                            putStr (show x ++ " ")
                            printIntArray xs

solve :: Int -> Int -> IO()
solve start end
    | start < 0 || end < 0 || start > end = return()
    | otherwise = do 
                    printIntArray (g start)
                    solve (start + 1) end

stoi :: String -> Int
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + (ord c - ord '0')

main :: IO ()
main = do
  [t] <- map (stoi . T.unpack) . T.words <$> I.getLine
  solve 0 (t - 1)