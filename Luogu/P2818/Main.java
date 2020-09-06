import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        BigInteger     n   = new BigInteger(br.readLine());
        BigInteger     m   = new BigInteger(br.readLine());
        if (m.compareTo(n) <= 0) {
            out.println(m);
        } else {
            BigInteger result = m.mod(n);
            if (result.compareTo(BigInteger.ZERO) == 0) {
                result = n;
            }
            out.println(result);
        }
        out.flush();
    }
}