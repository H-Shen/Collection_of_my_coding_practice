import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] arg) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         s;
        BigInteger     x, y, n;
        while (true) {
            s = br.readLine();
            if ("0".equals(s)) {
                break;
            }
            int t = Integer.parseInt(s);
            for (int i = 0; i < t; ++i) {
                String[] arguments = br.readLine().split(" ");
                x = new BigInteger(arguments[0]);
                y = new BigInteger(arguments[1]);
                n = new BigInteger(arguments[2]);
                out.println(x.modPow(y, n));
            }
        }
        out.flush();
    }
}
