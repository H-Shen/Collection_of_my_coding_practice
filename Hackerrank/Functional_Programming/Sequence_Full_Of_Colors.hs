-- https://www.hackerrank.com/challenges/sequence-full-of-colors/problem

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

countFreq :: String -> Char -> Int
countFreq s c = sum [1 | ch <- s, ch == c]

check :: String -> Int -> Int -> Char -> Char -> Bool
check [] _ _ _ _ = True
check (x : xs) a b ch_a ch_b
  | abs(a - b) > 1 = False
  | x == ch_a = check xs (a + 1) b ch_a ch_b
  | x == ch_b = check xs a (b + 1) ch_a ch_b
  | otherwise = check xs a b ch_a ch_b

solve :: String -> Bool
solve s = if (countFreq s 'R' == countFreq s 'G') 
  && (countFreq s 'Y' == countFreq s 'B') 
  && (check s 0 0 'R' 'G') 
  && (check s 0 0 'Y' 'B') then True else False

whileLoop' :: (Eq t, Num t) => t -> IO ()
whileLoop' 0 = return ()
whileLoop' n = do
  s <- getLine
  if solve s then putStrLn "True" else putStrLn "False"
  whileLoop' (n - 1)

main :: IO ()
main = do
  n <- readLn :: IO Int
  whileLoop' n
