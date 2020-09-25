-- https://www.hackerrank.com/challenges/functional-programming-warmups-in-recursion---fibonacci-numbers/problem

--Contributed by Ron Watkins
module Main where

myFibInLogImpl :: Integer -> (Integer, Integer)
myFibInLogImpl n
    | n < 0 = error "out of range"
    | n == 0 = (0, 1)
    | n > 0 = tempFunc n
    where
        tempFunc :: Integer -> (Integer, Integer)
        tempFunc x
            | x `mod` 2 /= 0 = (b, a + b)
            | otherwise = (a, b)
            where
            p = myFibInLogImpl (n `div` 2)
            a = fst p * (2 * snd p - fst p)
            b = (fst p) * (fst p) + (snd p) * (snd p)

fib n = fst (myFibInLogImpl (n - 1))


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
    input <- getLine
    print . fib . (read :: String -> Integer) $ input