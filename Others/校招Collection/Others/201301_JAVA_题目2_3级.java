// https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    private static BigInteger getFactorial(int n) throws IllegalArgumentException {
        if (n < 0) {
            throw new IllegalArgumentException();
        }
        if (n == 0) {
            return BigInteger.ONE;
        }
        BigInteger result = BigInteger.ONE;
        for (int i = 1; i <= n; ++i) {
            result = result.multiply(new BigInteger(Integer.toString(i)));
        }
        return result;
    }

    private static int getPathCount(int n, int m) {
        return getFactorial(n + m).divide(getFactorial(m).multiply(getFactorial(n))).intValue();
    }

    public static void main(String[] arg) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int m = in.nextInt();
            System.out.println(getPathCount(n, m));
        }
    }
}
