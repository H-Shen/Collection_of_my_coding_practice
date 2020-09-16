-- https://www.hackerrank.com/challenges/fp-solve-me-first/problem

solveMeFirst :: Integer -> Integer -> Integer
solveMeFirst a b = a + b

main = do
    val1 <- readLn
    val2 <- readLn
    print (solveMeFirst val1 val2)
