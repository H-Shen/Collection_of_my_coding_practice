import java.io.*;
import java.math.BigInteger;

public class Main {

    public static final String ZERO = "0";

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        BigInteger s = BigInteger.ZERO;
        String input;
        while (true) {
            input = br.readLine();
            if (input.compareTo(ZERO) == 0) {
                break;
            }
            s = s.add(new BigInteger(input));
        }
        out.println(s);
        out.flush();
    }
}