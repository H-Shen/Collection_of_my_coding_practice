-- https://www.hackerrank.com/challenges/fp-filter-positions-in-a-list/problem

f :: [Int] -> [Int]
f [] = []
f [x] = []
f [x, y] = [y]
f (x : y : xs) = y : f xs

-- This part deals with the Input and Output and can be used as it is. Do not modify it.
main = do
	inputdata <- getContents
	mapM_ (putStrLn. show). f. map read. lines $ inputdata