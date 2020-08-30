import java.io.*;
import java.math.BigInteger;

public class Main {

    public static final BigInteger UPPER_BOUND = new BigInteger(String.valueOf(Integer.MAX_VALUE));

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         input;
        while ((input = br.readLine()) != null) {
            String[]   arguments = input.split(" ");
            BigInteger a         = new BigInteger(arguments[0]);
            BigInteger b         = new BigInteger(arguments[2]);
            BigInteger c;
            if (arguments[1].compareTo("+") == 0) {
                c = a.add(b);
            } else {
                c = a.multiply(b);
            }
            out.println(input);
            if (a.compareTo(UPPER_BOUND) > 0) {
                out.println("first number too big");
            }
            if (b.compareTo(UPPER_BOUND) > 0) {
                out.println("second number too big");
            }
            if (c.compareTo(UPPER_BOUND) > 0) {
                out.println("result too big");
            }
        }
        out.flush();
    }
}