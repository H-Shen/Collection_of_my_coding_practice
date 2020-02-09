import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    private static StringBuilder process(String s) {
        StringBuilder sb = new StringBuilder(s);
        while (sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }
        while (sb.charAt(sb.length() - 1) == '0') {
            sb.deleteCharAt(sb.length() - 1);
        }
        if (sb.charAt(sb.length() - 1) == '.') {
            sb.deleteCharAt(sb.length() - 1);
        }
        return sb;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextBigDecimal()) {
            // input
            BigDecimal r = in.nextBigDecimal();
            int n = in.nextInt();
            BigDecimal result = r.pow(n);
            // output
            System.out.println(process(result.toPlainString()));
        }
    }
}