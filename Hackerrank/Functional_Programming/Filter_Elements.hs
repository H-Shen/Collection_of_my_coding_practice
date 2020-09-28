-- https://www.hackerrank.com/challenges/filter-elements/problem

-- Enter your code here. Read input from STDIN. Print output to STDOUT
import Data.List (sort)

parseInts :: String -> [Int]
parseInts str = map read (words str)

pack :: Eq a => [a] -> [[a]]
pack [] = []
pack (x : xs) =
  let (first, rest) = span (== x) xs
   in (x : first) : pack rest

encode :: [[b]] -> [(Int, b)]
encode xs = [(length (x : xy), x) | (x : xy) <- xs]

f :: [(Int, Int)] -> Int -> [Int]
f [] _ = []
f ((freq, element) : xs) k
  | freq >= k = element : f xs k
  | otherwise = f xs k

g :: [Int] -> [Int] -> [Int] -> [Int]
g _ [] _ = []
g [] _ _ = []
g (x : xs) l prev
  | elem x l && notElem x prev = x : g xs l (x : prev)
  | otherwise = g xs l prev

solve :: [Int] -> Int -> [Int]
solve a k = g a (f (encode (pack (sort a))) k) []

printIntArray :: [Int] -> IO ()
printIntArray [] = putStrLn "-1"
printIntArray [m] = putStrLn (show m)
printIntArray (x : xs) = do
  putStr (show x ++ " ")
  printIntArray xs

whileLoop :: Int -> IO ()
whileLoop 0 = return ()
whileLoop n = do
  s <- getLine
  let k = (parseInts s) !! 1
  s <- getLine
  let a = parseInts s
  printIntArray (solve a k)
  whileLoop (n - 1)

main :: IO ()
main = do
  t <- readLn :: IO Int
  whileLoop t