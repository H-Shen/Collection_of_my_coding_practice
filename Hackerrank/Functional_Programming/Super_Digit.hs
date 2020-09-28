-- https://www.hackerrank.com/challenges/super-digit/problem

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)

super_digit_impl :: String -> String
super_digit_impl s = case s of
                        [] -> []
                        [ch] -> [ch]
                        s -> super_digit_impl (show (sum [ord ch - ord '0' | ch <- s]))


main :: IO()
main = do
        s <- getLine
        let (n, k_str) = span (/= ' ') s
        let k = read k_str :: Integer
        let n_sum = toInteger (sum [ord ch - ord '0' | ch <- n]) * k
        putStrLn (super_digit_impl (show n_sum))
