import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {

        // input
        BufferedReader br  =new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));

        BigInteger a = new BigInteger(br.readLine());
        String op = br.readLine();
        BigInteger b = new BigInteger(br.readLine());

        // output
        if (op.compareTo("*") == 0) {
            out.println(a.multiply(b));
        } else {
            out.println(a.add(b));
        }
        out.flush();
    }
}