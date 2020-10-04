{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

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

fib n = fst (myFibInLogImpl (n + 2))

main :: IO()
main = do
    n <- readLn :: IO Integer
    (print . fib) n