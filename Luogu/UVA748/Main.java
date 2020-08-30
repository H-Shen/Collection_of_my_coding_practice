import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BigDecimal a;
        int b;
        Scanner in = new Scanner(System.in);
        while (in.hasNextBigDecimal()) {
            a = in.nextBigDecimal();
            b = in.nextInt();
            StringBuilder result = new StringBuilder(a.pow(b).stripTrailingZeros().toPlainString());
            StringBuilder output = new StringBuilder();
            if (result.indexOf(".") != -1) {
                int i = 0;
                while (result.charAt(i) == '0') {
                    ++i;
                }
                for (; i < result.length(); ++i) {
                    output.append(result.charAt(i));
                }
            } else {
                output = result;
            }

            System.out.println(output);
        }
    }
}
