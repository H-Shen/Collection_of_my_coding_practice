{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

fact :: (Eq p, Num p) => p -> p
fact 0 = 1
fact n = n * fact (n - 1)

factL :: [Integer]
factL = [fact i | i <- [0 .. 100]]

whileLoop :: Int -> IO ()
whileLoop 0 = return ()
whileLoop t = do
  n <- readLn :: IO Int
  print (factL !! n)
  whileLoop (t - 1)

main :: IO ()
main = do
  n <- readLn :: IO Int
  whileLoop n