{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I

stoi :: String -> Integer
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + toInteger (ord c - ord '0')

whileLoop' 0 = return()
whileLoop' n = do
                [x, y] <- map (stoi . T.unpack) . T.words <$> I.getLine
                print (x * y)
                whileLoop' (n - 1)

main :: IO ()
main = do
    t <- readLn :: IO Int
    whileLoop' t