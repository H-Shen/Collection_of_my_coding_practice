import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader        br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter           out = new PrintWriter(new OutputStreamWriter(System.out));
        String input;
        BigInteger a, b;
        while ((input = br.readLine()) != null) {
            a = new BigInteger(input);
            b = new BigInteger(br.readLine());
            out.println(a.multiply(b));
        }
        out.flush();
    }
}