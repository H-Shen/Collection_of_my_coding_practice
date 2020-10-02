/* 
-- Implementation in Haskell
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}
{-# LANGUAGE MultiParamTypeClasses #-}
{-# OPTIONS_GHC -O2 #-}

-- Obtain Stirling numbers of the second kind
f :: Integer -> Integer -> Integer
f n k
  | n < k = 0
  | k == 0 = 0
  | k == 1 = 1
  | k == 2 = 2^(n - 1) - 1
  | otherwise = k * f (n - 1) k + f (n - 1) (k - 1)

-- Read from stdin
readInput :: String -> [Integer]
readInput = (map read) . words

solve :: [Integer] -> [Integer]
solve [] = []
solve (x : y : xs) = (f x y) : (solve xs)

-- Output the result line by line
writeOutput :: [Integer] -> String
writeOutput = unlines . (map show)

main :: IO ()
main = interact (writeOutput . solve . readInput)

*/ 
import java.io.*;
import java.math.BigInteger;

public class Main {

    public static final int            MAXN = 105;
    public static       BigInteger     TWO  = new BigInteger("2");
    public static       BigInteger[][] dp   = new BigInteger[MAXN][MAXN];

    // Stirling Number of the Second Type
    public static BigInteger f(int n, int k) {
        if (n < k) {
            return BigInteger.ZERO;
        }
        if (k == 0) {
            if (dp[n][k] == null) {
                dp[n][k] = BigInteger.ZERO;
            }
            return dp[n][k];
        }
        if (k == 1) {
            if (dp[n][k] == null) {
                dp[n][k] = BigInteger.ONE;
            }
            return dp[n][k];
        }
        if (k == 2) {
            if (dp[n][k] == null) {
                dp[n][k] = TWO.pow(n - 1).subtract(BigInteger.ONE);
            }
            return dp[n][k];
        }
        if (dp[n - 1][k] == null) {
            dp[n - 1][k] = f(n - 1, k);
        }
        if (dp[n - 1][k - 1] == null) {
            dp[n - 1][k - 1] = f(n - 1, k - 1);
        }
        return dp[n - 1][k].multiply(new BigInteger(String.valueOf(k))).add(dp[n - 1][k - 1]);
    }

    public static void main(String[] arg) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         s;
        int            n, k;
        while ((s = br.readLine()) != null) {
            String[] parse = s.split(" ");
            n = Integer.parseInt(parse[0]);
            k = Integer.parseInt(parse[1]);
            out.println(f(n, k));
        }
        out.flush();
    }
}
