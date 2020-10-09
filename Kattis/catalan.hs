-- https://open.kattis.com/problems/catalan
--
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import qualified Data.Vector as V

maxLength :: Integer
maxLength = 5005

catalan :: Integer -> [Integer]
catalan 0 = [1]
catalan i = new_item : previous
  where
    previous = catalan (i - 1)
    new_item = 2 * (2 * i - 1) * (head previous) `div` (i + 1)

catalanList :: V.Vector Integer
catalanList = V.fromList (reverse (catalan maxLength))

whileLoop :: Int -> IO ()
whileLoop 0 = return ()
whileLoop t = do
  x <- readLn :: IO Int
  print (catalanList V.! x)
  whileLoop (t - 1)

main :: IO ()
main = do
  t <- readLn :: IO Int
  whileLoop t
