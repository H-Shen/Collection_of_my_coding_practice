import java.io.*;
import java.math.BigInteger;

public class Main {

    public static final int            MAX_A = 15;
    public static final int            MAX_N = 150;
    public static final BigInteger[][] L     = new BigInteger[MAX_A + 5][MAX_N + 5];

    public static void main(String[] args) throws IOException {
        // pre
        for (int a = 0; a <= MAX_A; ++a) {
            for (int i = 1; i <= MAX_N; ++i) {
                L[a][i] = new BigInteger(String.valueOf(a)).pow(i);
            }
        }
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         input;
        while ((input = br.readLine()) != null) {
            String[]   argument = input.split(" ");
            int        n        = Integer.parseInt(argument[0]);
            int        a        = Integer.parseInt(argument[1]);
            BigInteger sum      = BigInteger.ZERO;
            for (int i = 1; i <= n; ++i) {
                sum = sum.add(new BigInteger(String.valueOf(i)).multiply(L[a][i]));
            }
            out.println(sum);
        }
        out.flush();
    }
}