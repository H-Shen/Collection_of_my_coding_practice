// https://www.nowcoder.com/practice/2a05dcaa4cde4db989443f206ee3e5c5

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

    private static final int CERTAINTY = 70;

    public static void main(String[] arg) {
        Scanner in = new Scanner(System.in);
        int     t  = in.nextInt();
        for (int kase = 0; kase < t; ++kase) {
            String               s      = in.next();
            ArrayList<Character> number = new ArrayList<>();
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    number.add(s.charAt(i));
                }
            }

            // No digits found.
            if (number.isEmpty()) {
                System.out.println(0);
                continue;
            }

            StringBuilder sb = new StringBuilder();
            for (Character ch : number) {
                sb.append(ch);
            }
            BigInteger n = new BigInteger(sb.toString());

            // n == 0
            if (n.compareTo(BigInteger.ZERO) == 0) {
                System.out.println(0);
                continue;
            }

            // n is Prime
            if (n.isProbablePrime(CERTAINTY)) {
                System.out.println(n);
            } else {
                int start    = 2;
                int end      = (int) Math.sqrt(n.intValue()) + 1;
                int maxPrime = -1;
                while (start <= end) {
                    if (n.intValue() % start == 0) {
                        if (BigInteger.valueOf(start).isProbablePrime(CERTAINTY)) {
                            maxPrime = Math.max(maxPrime, start);
                        }
                        if (BigInteger.valueOf(n.intValue() / start).isProbablePrime(CERTAINTY)) {
                            maxPrime = Math.max(maxPrime, n.intValue() / start);
                        }
                    }
                    ++start;
                }
                System.out.println(maxPrime);
            }
        }
    }
}
