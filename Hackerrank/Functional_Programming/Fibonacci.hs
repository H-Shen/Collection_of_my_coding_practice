-- https://www.hackerrank.com/challenges/fibonacci-fp/problem

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

m :: Integer
m = 10^8 + 7

myFibInLogImpl :: Integer -> (Integer, Integer)
myFibInLogImpl n
    | n < 0 = error "out of range"
    | n == 0 = (0, 1)
    | n > 0 = tempFunc n
    where
        tempFunc :: Integer -> (Integer, Integer)
        tempFunc x
            | x `mod` 2 /= 0 = (b `mod` m, (a + b) `mod` m)
            | otherwise = (a `mod` m, b `mod` m)
            where
            p = myFibInLogImpl (n `div` 2)
            a = fst p * (2 * snd p - fst p)
            b = (fst p) * (fst p) + (snd p) * (snd p) 

myFibInLog :: Integer -> Integer
myFibInLog n
    | n < 0 = error "out of range"
    | otherwise = fst (myFibInLogImpl n)

whileLoop' :: (Eq t, Num t) => t -> IO ()
whileLoop' 0 = return ()
whileLoop' t = do
  n <- readLn :: IO Integer
  putStrLn (show (myFibInLog n))
  whileLoop' (t - 1)

main :: IO()
main = do
        t <- readLn :: IO Int
        whileLoop' t
