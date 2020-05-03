import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  =new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String[] temp = br.readLine().split(" ");
        Integer m = new Integer(temp[0]);
        Integer n = new Integer(temp[1]);
        BigInteger a = BigInteger.ZERO;
        BigInteger b = BigInteger.ONE;
        BigInteger c;
        if (n.equals(m)) {
            out.println(a);
        } else if (n.equals(m + 1)) {
            out.println(b);
        } else {
            Integer current = m + 1;
            while (n.compareTo(current) >= 0) {
                c = b;
                b = a.add(b);
                a = c;
                ++current;
            }
            out.println(b);
        }
        out.flush();
    }
}