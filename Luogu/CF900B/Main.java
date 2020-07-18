import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {

    public static final int LENGTH = 200005;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  =new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");
        BigDecimal a = new BigDecimal(input[0]);
        BigDecimal b = new BigDecimal(input[1]);
        char c = input[2].charAt(0);
        a = a.divide(b, LENGTH, RoundingMode.HALF_UP);
        String s = a.toPlainString();
        int position = -1;
        int i;
        for (i = 0; i < s.length() - 1; ++i) {
            if (s.charAt(i) == '.') {
                break;
            }
        }
        for (int j = 0; i < s.length() - 1; ++j, ++i) {
            if (s.charAt(i) == c) {
                position = j;
                break;
            }
        }
        // output
        out.println(position);
        out.flush();
    }
}