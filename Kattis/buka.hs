-- https://open.kattis.com/problems/buka
--
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}


main :: IO ()
main = do
        a <- getLine
        op <- getLine
        b <- getLine
        let m = read a::Integer
        let n = read b::Integer 
        if op == "*" then print(m * n) else print(m + n)
