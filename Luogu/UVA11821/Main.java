import java.io.*;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] arg) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         s;
        int            n   = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; ++i) {
            BigDecimal sum = BigDecimal.ZERO;
            while (true) {
                s = br.readLine();
                if (!"0".equals(s)) {
                    sum = sum.add(new BigDecimal(s));
                } else {
                    break;
                }
            }
            out.println(sum.stripTrailingZeros().toPlainString());
        }
        out.flush();
    }
}