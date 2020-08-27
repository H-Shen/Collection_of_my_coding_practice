// https://open.kattis.com/problems/checkingforcorrectness
//
import java.io.*;
import java.math.BigInteger;

public class Checking_For_Correctness {

    public static final BigInteger M = new BigInteger("10000");

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        BigInteger     a, b, c;
        String         in, op;
        while ((in = br.readLine()) != null) {
            String[] input = in.split(" ");
            a = new BigInteger(input[0]);
            op = input[1];
            b = new BigInteger(input[2]);
            switch (op) {
                case "+":
                    c = a.add(b).mod(M);
                    break;
                case "^":
                    c = a.modPow(b, M);
                    break;
                default:
                    c = a.multiply(b).mod(M);
                    break;
            }
            out.println(c);
        }
        out.flush();
    }
}
