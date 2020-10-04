import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] arg) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         s;
        BigInteger b, p, m;
        while ((s = br.readLine()) != null) {
            if ("".equals(s)) {
                b = new BigInteger(br.readLine());
            } else {
                b = new BigInteger(s);
            }
            p = new BigInteger(br.readLine());
            m = new BigInteger(br.readLine());
            out.println(b.modPow(p, m));
        }
        out.flush();
    }
}
