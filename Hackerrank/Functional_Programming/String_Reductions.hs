-- https://www.hackerrank.com/challenges/string-reductions/problem
-- Enter your code here. Read input from STDIN. Print output to STDOUT

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

solve :: String -> String -> String
solve [] _ = []
solve (x : xs) prev = if x `elem` prev then solve xs prev else x : solve xs (x : prev)

main :: IO ()
main = do
    s <- getLine
    putStrLn (solve s [])