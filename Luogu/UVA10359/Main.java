import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

    public static final int                   MAX_LENGTH = 255;
    public static final BigInteger            TWO        = new BigInteger("2");
    public static       ArrayList<BigInteger> A          = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // write your code here
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        // pre
        A.add(new BigInteger("0"));
        A.add(new BigInteger("1"));
        while (A.size() < MAX_LENGTH) {
            A.add(A.get(A.size() - 1).add(A.get(A.size() - 2).multiply(TWO)));
        }
        // input
        String s;
        while ((s = br.readLine()) != null) {
            out.println(A.get(Integer.parseInt(s) + 1));
        }
        out.flush();
    }
}
