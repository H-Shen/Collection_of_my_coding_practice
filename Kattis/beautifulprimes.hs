-- https://open.kattis.com/submissions/6185293
--
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I

g :: Integer -> Integer -> Bool
g val n = if toInteger(length (show val)) == n then True else False

h :: (Ord a, Num p) => a -> a -> p
h j i = if j < i then 2 else 11

generateArray :: Integer -> Integer -> [Integer]
generateArray i n = [h j i | j <- [0..n - 1]]

forLoop :: Integer -> Integer -> [Integer]
forLoop i n 
    | g val n == True = generateArray i n
    | otherwise = forLoop (i + 1) n
    where
        val = 2^i * 11^(n - i)

solve :: Integer -> IO()
solve n = putStrLn (unwords (map show (forLoop 0 n)))

stoi :: String -> Integer
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + toInteger (ord c - ord '0')

whileLoop' 0 = return()
whileLoop' t = do
                n <- readLn :: IO Integer
                solve n
                whileLoop' (t - 1)

main :: IO ()
main = do
    t <- readLn :: IO Int
    whileLoop' t
