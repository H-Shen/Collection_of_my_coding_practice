import java.io.*;
import java.math.BigInteger;

public class Main {

    public static final BigInteger MOD = new BigInteger("19260817");

    public static void main(String[] args) throws IOException {

        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

        BigInteger a  = new BigInteger(br.readLine());
        BigInteger b  = new BigInteger(br.readLine());
        try {
            BigInteger bRev = b.modInverse(MOD);
            out.println(a.multiply(bRev).mod(MOD));
        } catch (ArithmeticException e) {
            out.println("Angry!");
        }
        out.flush();
    }
}