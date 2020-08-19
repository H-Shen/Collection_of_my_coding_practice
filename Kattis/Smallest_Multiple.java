// https://open.kattis.com/problems/smallestmultiple
//
import java.io.*;
import java.math.BigInteger;

public class Smallest_Multiple {

    public static BigInteger lcm(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(a.gcd(b));
    }

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         input;
        while ((input = br.readLine()) != null) {
            String[]   inputArray = input.split(" ");
            BigInteger result     = BigInteger.ONE;
            for (int i = 0; i < inputArray.length; ++i) {
                result = lcm(result, new BigInteger(inputArray[i]));
            }
            out.println(result);
        }
        out.flush();
    }
}
