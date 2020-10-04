-- https://open.kattis.com/problems/catalansquare
--
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

catalan :: Integer -> [Integer]
catalan 0 = [1]
catalan i = new_item : previous
  where
    previous = catalan (i - 1)
    new_item = 2 * (2 * i - 1) * (head previous) `div` (i + 1)

main :: IO ()
main = do
  n <- readLn :: IO Integer
  let c = catalan n
  let cRev = reverse c
  print (mySum c cRev)
  where
    mySum (x : xs) (y : ys) = x * y + mySum xs ys
    mySum [] [] = 0
