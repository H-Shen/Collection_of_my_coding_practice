import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; ++i) {
            String[] arguments = br.readLine().split(" ");
            BigInteger a = new BigInteger(arguments[0]);
            BigInteger b = new BigInteger(arguments[2]);
            BigInteger c = a.gcd(b);
            a = a.divide(c);
            b = b.divide(c);
            out.println(a + " / " + b);
        }
        out.flush();
    }
}