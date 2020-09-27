-- https://www.hackerrank.com/challenges/string-o-permute/problem
-- Enter your code here. Read input from STDIN. Print output to STDOUT

swap :: String -> String
swap [] = []
swap (first : second : others) = second : first : swap others

whileLoop :: Int -> IO()
whileLoop 0 = return()
whileLoop n = do
                s <- getLine
                putStrLn (swap s)
                whileLoop (n - 1)

main :: IO()
main = do
    n <- readLn :: IO Int
    whileLoop n