-- https://www.hackerrank.com/challenges/prefix-compression/problem

-- Enter your code here. Read input from STDIN. Print output to STDOUT

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

prefix :: String -> String -> String -> String
prefix "" _ prev = reverse prev
prefix _ "" prev = reverse prev
prefix (x : xs) (y : ys) prev = if x == y then prefix xs ys (x : prev) else reverse prev

getRest :: String -> Int -> String
getRest s n
  | n <= length s = temp
  | otherwise = ""
  where
    temp = [j | (i, j) <- zip [1 ..] s, i > n]

solve :: String -> String -> (String, String, String)
solve a b = (s1, s2, s3)
  where
    s1 = prefix a b ""
    len = length s1
    s2 = getRest a len
    s3 = getRest b len

print' :: String -> IO ()
print' "" = print 0
print' s = putStrLn ((show (length s)) ++ " " ++ s)

main :: IO ()
main = do
  a <- getLine
  b <- getLine
  let (m, n, p) = solve a b
  print' m
  print' n
  print' p