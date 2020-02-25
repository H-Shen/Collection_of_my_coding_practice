// https://open.kattis.com/problems/jackpot
//
import java.math.BigInteger;
import java.util.Scanner;

public class Jackpot {

    private static final BigInteger BILLION = new BigInteger("1000000000");

    private static BigInteger gcd(BigInteger a, BigInteger b) {
        // Case 1:
        if (a.compareTo(BigInteger.ZERO) < 0) {
            return gcd(a.negate(), b);
        }
        // Case 2:
        if (b.compareTo(BigInteger.ZERO) < 0) {
            return gcd(a, b.negate());
        }
        // Case 3:
        if (a.compareTo(BigInteger.ZERO) == 0 || b.compareTo(BigInteger.ZERO) == 0) {
            return BigInteger.ZERO;
        }
        // Case 4:
        BigInteger t;
        while (b.compareTo(BigInteger.ZERO) > 0) {
            t = a.mod(b);
            a = b;
            b = t;
        }
        return a;
    }

    private static BigInteger lcm(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(gcd(a, b));
    }

    public static void main(String[] arg) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; ++i) {
            int w = in.nextInt();
            BigInteger result = BigInteger.ONE;
            for (int j = 0; j < w; ++j) {
                if (j == 0) {
                    result = in.nextBigInteger();
                } else {
                    result = lcm(result, in.nextBigInteger());
                }
            }
            if (result.compareTo(BILLION) <= 0) {
                System.out.println(result);
            } else {
                System.out.println("More than a billion.");
            }
        }
    }
}
