-- https://www.hackerrank.com/challenges/string-compression/problem
-- Enter your code here. Read input from STDIN. Print output to STDOUT

pack :: [Char] -> [String]
pack [] = []
pack (x:xs) = let (first, rest) = span (== x) xs
               in (x: first) : pack rest

encode :: String -> [(Int, Char)]
encode s = [(length i, head i) | i <- pack s]

f :: Int -> Char -> String
f n ch = if n == 1 then [ch] else ch : show n

solve :: String -> String
solve s = concat [f n ch | (n, ch) <- encode s]

main :: IO()
main = do
        s <- getLine
        putStrLn (solve s)
