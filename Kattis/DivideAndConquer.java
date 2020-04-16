// https://open.kattis.com/problems/divideandconquer
//
import java.math.BigInteger;
import java.util.Scanner;

public class DivideAndConquer {

    public static final BigInteger TWO = new BigInteger("2");

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger b = in.nextBigInteger();
        BigInteger d = in.nextBigInteger();
        if (d.compareTo(TWO) == 0) {
            if (b.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
                System.out.println("no");
            } else {
                System.out.println("yes");
            }
        } else if (b.mod(d).compareTo(BigInteger.ZERO) == 0) {
            System.out.println("no");
        } else {
            BigInteger temp = d.subtract(BigInteger.ONE);
            while (temp.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
                temp = temp.divide(TWO);
            }
            BigInteger result = b.modPow(temp, d);
            if (result.compareTo(BigInteger.ONE) == 0) {
                System.out.println("no");
            } else {
                System.out.println("yes");
            }
        }
    }
}
