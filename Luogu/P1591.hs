{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I

stoi :: String -> Int
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + (ord c - ord '0')

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1)

solve'' :: Integer -> Char -> Integer
solve'' n a = sum [1 | i <- show $ fact n, i == a]

whileLoop :: Int -> IO ()
whileLoop 0 = return()
whileLoop t = do
                [n, a] <- map (stoi . T.unpack) . T.words <$> I.getLine
                print (solve'' (toInteger n) (toEnum (ord '0' + a)))
                whileLoop (t - 1)
main :: IO ()
main = do
    t <- readLn :: IO Int
    whileLoop t


