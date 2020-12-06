// https://open.kattis.com/problems/simplearithmetic
//
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;

public class Simple_Arithmetic {

    public static void main(String[] args) throws IOException {
        // write your code here
        BufferedReader br    = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out   = new PrintWriter(new OutputStreamWriter(System.out));
        String[]       input = br.readLine().split(" ");
        BigInteger     a     = new BigInteger(input[0]);
        BigInteger     b     = new BigInteger(input[1]);
        BigInteger     c     = new BigInteger(input[2]);
        if (a.multiply(b).mod(c).compareTo(BigInteger.ZERO) == 0) {
            out.println(a.multiply(b).divide(c));
        } else {
            BigDecimal result = new BigDecimal(a.multiply(b)).divide(new BigDecimal(c), 15, RoundingMode.HALF_UP);
            out.println(result.toPlainString());
        }
        out.flush();
    }
}
