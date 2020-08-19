// https://open.kattis.com/problems/houseofcards
//
import java.io.*;
import java.math.BigInteger;

public class House_Of_Cards {

    public static final BigInteger EIGHT = new BigInteger("8");
    public static final BigInteger FIVE  = new BigInteger("5");

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        BigInteger     h   = new BigInteger(br.readLine());
        while (h.mod(EIGHT).compareTo(BigInteger.ZERO) != 0 && h.subtract(FIVE).mod(EIGHT).compareTo(BigInteger.ZERO) != 0) {
            h = h.add(BigInteger.ONE);
        }
        out.println(h);
        out.flush();
    }
}
