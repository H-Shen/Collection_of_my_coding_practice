{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

-- constant
modulo :: Integer
modulo = 10 ^ 500

digits :: Int
digits = 500

digitsInALine :: Int
digitsInALine = 50

k :: Double
k = logBase 10 2.0

getDigits :: Integer -> Integer
getDigits p = floor ((fromInteger p) * k + 1.0)

solve :: Integer -> Integer
solve p = ((log_modpow 2 p modulo) - 1) `mod` modulo

paddingLeft :: String -> Int -> String
paddingLeft s x
  | x >= digits = s
  | otherwise = '0' : paddingLeft s (x + 1)

printStr :: String -> Int -> IO ()
printStr [] _ = return ()
printStr (x : xs) n
  | n < digitsInALine = do
    putChar x
    printStr xs (n + 1)
  | n == digitsInALine = do
    putChar x
    putChar '\n'
    printStr xs 1
  | otherwise = error "invalid length"

log_modpow :: Integer -> Integer -> Integer -> Integer
log_modpow _ _ 0 = error "modulo cannot be 0"
log_modpow _ 0 _ = 1
log_modpow a b p
  | b `mod` 2 /= 0 = (result * a) `mod` p
  | otherwise = result
  where
    temp = log_modpow a (b `div` 2) p
    result = (temp * temp) `mod` p

main :: IO ()
main = do
  p <- readLn :: IO Integer
  print (getDigits p)
  let temp = show (solve p)
  printStr (paddingLeft temp (length temp)) 1