import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br    = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out   = new PrintWriter(new OutputStreamWriter(System.out));
        String[]       input = br.readLine().split(" ");
        int            k     = Integer.parseInt(input[0]);
        BigInteger     x     = new BigInteger(input[1]);
        // output
        out.println(new BigInteger("10").pow(k).add(x));
        out.flush();
    }
}