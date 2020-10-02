{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

kase :: Int
kase = 10

whileLoop :: Int -> IO ()
whileLoop 0 = return ()
whileLoop t = do
  a <- readLn :: IO Integer
  b <- readLn :: IO Integer
  print ((a + b) `div` 2)
  print ((a - b) `div` 2)
  whileLoop (t - 1)

main :: IO ()
main = do
  whileLoop kase
