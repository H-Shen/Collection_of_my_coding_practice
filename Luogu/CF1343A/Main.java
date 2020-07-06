import java.io.*;
import java.math.BigInteger;

public class Main {

    public static final BigInteger TWO = new BigInteger("2");
    
    public static final BigInteger THREE = new BigInteger("3");

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  =new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        int t =  new Integer(br.readLine());
        for (int i = 0; i < t; ++i) {
            BigInteger n = new BigInteger(br.readLine());
            BigInteger a = THREE;
            BigInteger b = TWO;
            while (n.mod(a).compareTo(BigInteger.ZERO) != 0) {
                b = b.multiply(TWO);
                a = a.add(b);
            }
            out.println(n.divide(a));
        }
        out.flush();
    }
}