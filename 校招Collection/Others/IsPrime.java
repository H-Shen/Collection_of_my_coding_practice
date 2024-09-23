// https://www.nowcoder.com/practice/5fd9c28b1ce746dd99287a04d8fa9002

import java.util.Scanner;

public class IsPrime {

    private static final int CERTAINTY = 100;

    public static void main(String[] arg) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextBigInteger()) {
            if (scanner.nextBigInteger().isProbablePrime(CERTAINTY)) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
