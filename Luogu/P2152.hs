{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

main :: IO()
main = do
  a <- readLn :: IO Integer
  b <- readLn :: IO Integer
  print (gcd a b)