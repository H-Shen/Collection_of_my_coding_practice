import java.io.*;
import java.math.BigInteger;

public class Main {

    public static BigInteger[] dp;

    public static void main(String[] arg) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        int            n   = Integer.parseInt(br.readLine());
        dp = new BigInteger[n + 5];
        dp[0] = BigInteger.ZERO;
        dp[1] = BigInteger.ONE;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 != 0) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1].add(dp[i >> 1]);
            }
        }
        out.println(dp[n].mod(new BigInteger("1000000000")));
        out.flush();
    }
}
