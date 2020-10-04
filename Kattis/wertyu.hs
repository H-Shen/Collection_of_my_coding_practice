-- https://open.kattis.com/problems/wertyu
--
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import System.IO (isEOF)

a :: String
a = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./ "

b :: String
b = "‘1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. "

elemIndex :: Char -> String -> Int
elemIndex ch s
  | notElem ch s = -1
  | otherwise = minimum [i | (i, j) <- zip [0 ..] s, j == ch]

solve :: String -> String
solve s = [f ch | ch <- s]
  where
    f :: Char -> Char
    f c = if elem c a then b !! (elemIndex c a) else c

main :: IO ()
main = do
  read_eof <- isEOF
  if read_eof
    then return ()
    else do
      s <- getLine
      putStrLn (solve s)
      main
