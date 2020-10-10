// https://open.kattis.com/problems/batmanacci
//
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Batmanacci {

    public static final int OFFSET = 3;

    public static final int LOWER_BOUND = 2;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br    = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out   = new PrintWriter(new OutputStreamWriter(System.out));
        String[]       input = br.readLine().split(" ");
        int            n     = Integer.parseInt(input[0]);
        BigInteger     k     = new BigInteger(input[1]);

        ArrayList<BigInteger> tempArray = new ArrayList<>();
        tempArray.add(BigInteger.ZERO);
        tempArray.add(BigInteger.ONE);
        for (int i = 0; i < n + OFFSET; ++i) {
            tempArray.add(tempArray.get(tempArray.size() - 2).add(tempArray.get(tempArray.size() - 1)));
        }
        while (n > LOWER_BOUND) {
            if (k.compareTo(tempArray.get(n - LOWER_BOUND)) <= 0) {
                n -= LOWER_BOUND;
            } else {
                k = k.subtract(tempArray.get(n - LOWER_BOUND));
                --n;
            }
        }

        // output
        if (n == 1) {
            out.println('N');
        } else {
            out.println('A');
        }
        out.flush();
    }
}
/* Haskell Code:

{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

import Data.Char (ord)
import qualified Data.Text as T
import qualified Data.Text.IO as I
import qualified Data.Vector as V

offset :: Integer
offset = 5

lowerBound :: Integer
lowerBound = 2

fib :: Integer -> [Integer]
fib 0 = [0]
fib 1 = [1, 0]
fib i = new_item : previous
  where
    previous = fib (i - 1)
    new_item = previous !! 0 + previous !! 1

whileLoop :: Integer -> Integer -> V.Vector Integer -> IO ()
whileLoop n k fibList
  | n > lowerBound = case () of
    () | k <= (fibList V.! fromIntegral (n - lowerBound)) ->  ($!) whileLoop (n - lowerBound) k fibList
    () | otherwise -> ($!) whileLoop (n - 1) (k - (fibList V.! fromIntegral (n - lowerBound))) fibList
  | n == 1 = putChar 'N'
  | otherwise = putChar 'A'

stoi :: String -> Integer
stoi s = stoi' s 0
  where
    stoi' [] n = n
    stoi' (c : cs) n = stoi' cs $ n * 10 + toInteger (ord c - ord '0')

main :: IO ()
main = do
  [n, k] <- map (stoi . T.unpack) . T.words <$> I.getLine
  ($!) whileLoop n k (V.fromList (reverse (fib (n + offset))))

*/
