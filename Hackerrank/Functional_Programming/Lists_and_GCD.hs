-- https://www.hackerrank.com/challenges/lists-and-gcd/problem

-- Enter your code here. Read input from STDIN. Print output to STDOUT

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import Data.List (sortBy)
import qualified Data.Text as T
import qualified Data.Text.IO as I

f :: [Int] -> [(Int, Int)]
f [] = []
f [_] = []
f (x : y : xs) = (x, y) : f xs

g :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
g [] _ = []
g _ [] = []
g a b = [(i, min j l) | (i, j) <- a, (k, l) <- b, i == k && i `elem` p]
  where
    p = [i | (i, _) <- a, i `elem` [j | (j, _) <- b]]

gcdList :: [[(Int, Int)]] -> [(Int, Int)]
gcdList [] = []
gcdList [m] = g m m
gcdList [x, y] = g x y
gcdList (x : y : xs) = g (g x y) (gcdList xs)

printPairIntArray :: [(Int, Int)] -> IO ()
printPairIntArray [] = return ()
printPairIntArray [(x, y)] = putStrLn (show x ++ " " ++ show y)
printPairIntArray ((x, y) : xs) = do
  putStr (show x ++ " " ++ show y ++ " ")
  printPairIntArray xs

stoi :: String -> Int
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + (ord c - ord '0')

whileLoop :: (Eq t, Num t) => t -> [[Int]] -> IO ()
whileLoop 0 l = printPairIntArray ( sortBy (\(a, _) (b, _) -> compare a b) (gcdList [f i | i <- l]))
whileLoop t prev = do
  arr <- map (stoi . T.unpack) . T.words <$> I.getLine
  whileLoop (t - 1) (arr : prev)

main :: IO ()
main = do
  [t] <- map (stoi . T.unpack) . T.words <$> I.getLine
  whileLoop t []