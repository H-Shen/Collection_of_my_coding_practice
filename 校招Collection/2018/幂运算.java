// https://www.nowcoder.com/practice/2ee36922acfe4b26bb7cceb5fc9a89a2

import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    public static void main(String[] arg) {

        Scanner in        = new Scanner(System.in);
        boolean firstItem = true;
        while (in.hasNext()) {

            // get input
            String input = in.next();
            String r_str;
            if (input.contains(".")) {
                // trim zero
                int lastIndexThatIsNotZero = input.length() - 1;
                while (input.charAt(lastIndexThatIsNotZero) != '.') {
                    if (input.charAt(lastIndexThatIsNotZero) == '0') {
                        --lastIndexThatIsNotZero;
                    } else {
                        break;
                    }
                }
                if (input.charAt(lastIndexThatIsNotZero) == '.') {
                    r_str = input.substring(0, lastIndexThatIsNotZero);
                } else {
                    r_str = input.substring(0, lastIndexThatIsNotZero + 1);
                }
            } else {
                r_str = input;
            }

            BigDecimal r      = new BigDecimal(r_str);
            int        n      = in.nextInt();
            BigDecimal result = r;
            for (int i = 0; i < n - 1; ++i) {
                result = result.multiply(r);
            }
            if (firstItem) {
                firstItem = false;
            } else {
                System.out.print(" ");
            }
            System.out.print(result.toPlainString());
        }
    }
}
