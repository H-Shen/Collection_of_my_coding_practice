// https://open.kattis.com/problems/generalizedrecursivefunctions
//
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;

public class Generalized_Recursive_Functions {

    public static HashMap<Integer, BigInteger> memo;
    public static int                          n;
    public static ArrayList<Integer>           a, b;
    public static BigInteger c, d;

    public static int convert(int x, int y) {
        return x * 10000 + y;
    }

    public static BigInteger f(int x, int y) {
        if (memo.containsKey(convert(x, y))) {
            return memo.get(convert(x, y));
        }
        if (x > 0 && y > 0) {
            BigInteger sum = BigInteger.ZERO;
            n = a.size();
            for (int i = 0; i < n; ++i) {
                int x_ = x - a.get(i);
                int y_ = y - b.get(i);
                if (!memo.containsKey(convert(x_, y_))) {
                    memo.put(convert(x_, y_), f(x_, y_));
                }
                sum = sum.add(memo.get(convert(x_, y_)));
            }
            sum = sum.add(c);
            memo.put(convert(x, y), sum);
            return sum;
        }
        memo.put(convert(x, y), d);
        return d;
    }

    public static void main(String[] args) throws IOException {

        // write your code here
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         s   = br.readLine();
        int            t   = Integer.parseInt(s);
        for (int i = 0; i < t; ++i) {
            String[] p = br.readLine().split(" ");
            a = new ArrayList<>();
            b = new ArrayList<>();
            memo = new HashMap<>();
            for (int j = 0; j < p.length - 2; ++j) {
                if (j % 2 == 0) {
                    a.add(Integer.valueOf(p[j]));
                } else {
                    b.add(Integer.valueOf(p[j]));
                }
            }
            c = new BigInteger(p[p.length - 2]);
            d = new BigInteger(p[p.length - 1]);
            String[] q = br.readLine().split(" ");
            for (int j = 0; j < q.length; j += 2) {
                out.println(f(Integer.parseInt(q[j]), Integer.parseInt(q[j + 1])));
            }
            out.println();
        }
        out.flush();
    }
}
