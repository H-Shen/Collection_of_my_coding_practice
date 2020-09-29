{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I

whileLoop :: Integer -> Integer -> Integer -> Integer -> Integer
whileLoop a b n current
    | n >= current = whileLoop b (a + b) n (current + 1)
    | otherwise = b

solve' m n
    | m == n = 0
    | m + 1 == n = 1
    | otherwise = whileLoop 0 1 n (m + 1)

stoi :: String -> Int
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + (ord c - ord '0')

main :: IO ()
main = do
    [m, n] <- map (stoi . T.unpack) . T.words <$> I.getLine
    print (solve' (toInteger m) (toInteger n))