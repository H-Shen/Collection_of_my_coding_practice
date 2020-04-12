import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    private static HashMap<BigInteger, BigInteger> hm = new HashMap<>();
    private static BigInteger TWO = new BigInteger("2");

    public static BigInteger solve(BigInteger n) {
        if (n.compareTo(BigInteger.ZERO) == 0) {
            return BigInteger.ZERO;
        }
        if (n.compareTo(BigInteger.ONE) == 0) {
            return BigInteger.ONE;
        }
        if (hm.containsKey(n)) {
            return hm.get(n);
        }
        BigInteger result;
        BigInteger i = n.divide(TWO);
        if (n.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
            result = solve(i);
        } else {
            result = solve(i).add(solve(i.add(BigInteger.ONE)));
        }
        hm.put(n, result);
        return result;
    }

    public static void main(String[] arg) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; ++i) {
            System.out.println(solve(in.nextBigInteger()));
        }
    }
}