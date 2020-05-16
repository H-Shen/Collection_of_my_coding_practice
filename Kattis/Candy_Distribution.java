// https://open.kattis.com/problems/candydistribution
//
import java.io.*;
import java.math.BigInteger;

public class Candy_Distribution {

    public static final BigInteger LOWER_BOUND = BigInteger.ONE;
    public static final BigInteger UPPER_BOUND = new BigInteger("1000000000");

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        int            t   = Integer.parseInt(br.readLine());
        BigInteger     k, c, c_inv;
        for (int i = 0; i < t; ++i) {
            String[] temp = br.readLine().split(" ");
            k = new BigInteger(temp[0]);
            c = new BigInteger(temp[1]);
            // output
            if (k.compareTo(LOWER_BOUND) == 0) {
                if (c.compareTo(BigInteger.ONE) == 0) {
                    out.println(2);
                } else {
                    out.println(1);
                }
                continue;
            }
            if (c.compareTo(BigInteger.ONE) == 0) {
                BigInteger tempBigInteger = k.add(c);
                if (tempBigInteger.compareTo(UPPER_BOUND) <= 0) {
                    out.println(tempBigInteger);
                } else {
                    out.println("IMPOSSIBLE");
                }
                continue;
            }

            try {
                c_inv = c.modInverse(k);
                if (c_inv.compareTo(UPPER_BOUND) <= 0 && c_inv.compareTo(LOWER_BOUND) >= 0 && c_inv.multiply(c).subtract(BigInteger.ONE).compareTo(BigInteger.ZERO) > 0) {
                    out.println(c_inv);
                } else {
                    out.println("IMPOSSIBLE");
                }
            } catch (Exception e) {
                out.println("IMPOSSIBLE");
            }
        }
        out.flush();
    }
}
