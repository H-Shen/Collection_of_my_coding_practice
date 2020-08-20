// https://open.kattis.com/problems/divideandconquer
//
import java.io.*;
import java.math.BigInteger;

public class Divide_And_Conquer {

    public static final BigInteger TWO = new BigInteger("2");

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br    = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out   = new PrintWriter(new OutputStreamWriter(System.out));
        String[]       input = br.readLine().split(" ");

        BigInteger b       = new BigInteger(input[0]);
        BigInteger d       = new BigInteger(input[1]);
        boolean    haveAns = true;
        if (d.compareTo(TWO) == 0) {
            if (b.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
                haveAns = false;
            }
        } else if (b.mod(d).compareTo(BigInteger.ZERO) == 0) {
            haveAns = false;
        } else {
            BigInteger temp = d.subtract(BigInteger.ONE);
            while (temp.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
                temp = temp.divide(TWO);
            }
            BigInteger result = b.modPow(temp, d);
            if (result.compareTo(BigInteger.ONE) == 0) {
                haveAns = false;
            }
        }

        // output
        if (haveAns) {
            out.println("yes");
        } else {
            out.println("no");
        }
        out.flush();
    }
}
