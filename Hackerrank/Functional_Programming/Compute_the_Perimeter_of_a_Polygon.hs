-- https://www.hackerrank.com/challenges/lambda-march-compute-the-perimeter-of-a-polygon/problem

-- Enter your code here. Read input from STDIN. Print output to STDOUT

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I
import Text.Printf

stoi :: String -> Int
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + (ord c - ord '0')

whileLoop' :: Int -> [(Int, Int)] -> IO ()
whileLoop' 0 s
  | s == [] = error ""
  | otherwise = do
    let result = getCircumference (splitPoints (s ++ [head s]))
    if floor result == ceiling result then print (floor result) else printf "%.1f\n" result
    return ()
whileLoop' n s = do
  [x, y] <- map (stoi . T.unpack) . T.words <$> I.getLine
  whileLoop' (n - 1) ((x, y) : s)

getDistance :: (Int, Int) -> (Int, Int) -> Double
getDistance (x1, y1) (x2, y2) = sqrt (fromIntegral ((x1 - x2) ^ 2 + (y1 - y2) ^ 2))

getCircumference :: [((Int, Int), (Int, Int))] -> Double
getCircumference s = sum [getDistance i j | (i, j) <- s]

splitPoints :: [(Int, Int)] -> [((Int, Int), (Int, Int))]
splitPoints [] = []
splitPoints (x : []) = []
splitPoints (x : y : xs) = (x, y) : splitPoints (y : xs)

main :: IO ()
main = do
  n <- readLn :: IO Int
  whileLoop' n []