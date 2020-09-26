-- https://www.hackerrank.com/challenges/string-mingling/problem

-- Enter your code here. Read input from STDIN. Print output to STDOUT

f :: [a] -> [a] -> [a]
f a b = concat [(fst p) : (snd p) : [] | p <- zip a b]

main :: IO()
main = do 
        a <- getLine
        b <- getLine
        putStrLn (f a b)