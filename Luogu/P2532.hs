{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

whileLoop :: Integer -> Integer -> Integer -> Integer
whileLoop current end prevResult
  | current >= end = prevResult
  | otherwise = whileLoop (current + 1) end result
  where
    result = ((current * 4 - 2) * prevResult) `div` (current + 1)

main :: IO ()
main = do
  n <- readLn :: IO Integer
  print (whileLoop 1 (n + 1) 1)