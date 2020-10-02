-- https://www.hackerrank.com/challenges/eval-ex/problem

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Text.Printf (printf)

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1)

factList :: [Double]
factList = [fromInteger (fact i) | i <- [0 .. 9]]

expr :: Double -> Double
expr x = sum [(x ** fromIntegral (i)) / (factList !! i) | i <- [0 .. 9]]

whileLoop :: Int -> IO ()
whileLoop 0 = return ()
whileLoop t = do
  x <- readLn :: IO Double
  printf "%.4f\n" (expr x)
  whileLoop (t - 1)

main :: IO ()
main = do
  n <- readLn :: IO Int
  whileLoop n