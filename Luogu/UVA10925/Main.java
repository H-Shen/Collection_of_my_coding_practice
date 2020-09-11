import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br   = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out  = new PrintWriter(new OutputStreamWriter(System.out));
        int            kase = 1;
        while (true) {
            String[] arguments = br.readLine().split(" ");
            int      n         = Integer.parseInt(arguments[0]);
            int      f         = Integer.parseInt(arguments[1]);
            if (n == 0 && f == 0) {
                break;
            }
            BigInteger sum = BigInteger.ZERO;
            for (int i = 0; i < n; ++i) {
                sum = sum.add(new BigInteger(br.readLine()));
            }
            out.println("Bill #" + kase + " costs " + sum + ": each friend should pay " + sum.divide(new BigInteger(String.valueOf(f))));
            out.println();
            ++kase;
        }
        out.flush();
    }
}