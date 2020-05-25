import java.io.*;
import java.math.BigInteger;
import java.util.HashSet;

public class Main {

    public static final BigInteger TWO = new BigInteger("2");
    public static final BigInteger THREE = new BigInteger("3");

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        BigInteger n = new BigInteger(br.readLine());

        HashSet<BigInteger> hashMap = new HashSet<>();
        while (n.compareTo(BigInteger.ONE) > 0) {
            if (hashMap.contains(n)) {
                out.println("NIE");
                out.flush();
                return;
            }
            hashMap.add(n);
            if (n.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
                n = n.divide(TWO);
            } else {
                n = n.multiply(THREE).add(THREE);
            }
        }
        out.println("TAK");
        out.flush();
    }
}