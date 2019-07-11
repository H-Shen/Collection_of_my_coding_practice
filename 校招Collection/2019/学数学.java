// https://www.nowcoder.com/practice/b7da655789d941dd8f8bfc547443b5d1

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner    in = new Scanner(System.in);
        BigInteger n  = in.nextBigInteger();
        BigInteger mid;

        if (n.intValue() % 2 == 0) {
            mid = n.divide(new BigInteger("2"));
        } else {
            mid = n.subtract(BigInteger.ONE).divide(new BigInteger("2"));
        }

        int        counter = 0;
        BigInteger i       = BigInteger.ONE;
        while (i.compareTo(mid) <= 0) {
            if (i.isProbablePrime(100) && n.subtract(i).isProbablePrime(100)) {
                ++counter;
            }
            i = i.add(BigInteger.ONE);
        }
        System.out.println(counter);
    }
}
