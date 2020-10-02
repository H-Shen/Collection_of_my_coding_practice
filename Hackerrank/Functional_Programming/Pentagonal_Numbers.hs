-- https://www.hackerrank.com/challenges/pentagonal-numbers/problem
-- Enter your code here. Read input from STDIN. Print output to STDOUT

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

f :: Integer -> Integer
f n = n*(3*n - 1) `div` 2

whileLoop :: Int -> IO()
whileLoop 0 = return()
whileLoop t = do
                n <- readLn :: IO Integer
                print (f n)
                whileLoop (t - 1)

main :: IO()
main = do
        t <- readLn :: IO Int
        whileLoop t