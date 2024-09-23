// https://www.nowcoder.com/practice/e9a4919b8848451d9aff81e3cdd133b1

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] arg) {

        Scanner    in   = new Scanner(System.in);
        int        n    = in.nextInt();
        BigInteger base = new BigInteger("2");
        BigInteger pow  = new BigInteger("2");
        for (int i = 0; i < n - 1; ++i) {
            base = base.multiply(pow);
        }
        System.out.println(base);
    }
}
