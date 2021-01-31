-- https://open.kattis.com/problems/abstractpainting
--
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I

myMod :: Integer
myMod = 10^9 + 7

stoi :: String -> Integer
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + toInteger (ord c - ord '0')
    
whileLoop :: Int -> IO ()
whileLoop 0 = return()
whileLoop t = do
                [r, c] <- map (stoi . T.unpack) . T.words <$> I.getLine
                print (3^(r+c)*2^(r*c) `mod` myMod)
                whileLoop (t - 1)
                
main :: IO ()
main = do
        t <- readLn :: IO Int
        whileLoop t
