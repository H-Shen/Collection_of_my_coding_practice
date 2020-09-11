import java.io.*;
import java.math.BigInteger;

public class Main {

    public static final int          MAXN        = 1002;
    public static       BigInteger[] bigIntegers = new BigInteger[MAXN];

    public static void main(String[] args) throws IOException {
        // pre
        bigIntegers[0] = BigInteger.ONE;
        bigIntegers[1] = BigInteger.ONE;
        for (int i = 2; i < MAXN; ++i) {
            bigIntegers[i] = bigIntegers[i - 1].multiply(new BigInteger(String.valueOf(i)));
        }
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         input;
        while ((input = br.readLine()) != null) {
            out.println(input + '!');
            out.println(bigIntegers[Integer.parseInt(input)]);
        }
        out.flush();
    }
}