solve :: Integer -> Integer -> Integer
solve m n
  | m <= n = m
  | result == 0 = n
  | otherwise = result
  where
    result = m `mod` n

main :: IO ()
main = do
  n <- readLn :: IO Integer
  m <- readLn :: IO Integer
  putStrLn (show (solve m n))