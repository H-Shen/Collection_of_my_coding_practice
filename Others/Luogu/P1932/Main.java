import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        //A+B A-B A*B A/B A%B
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        System.out.println(a.add(b));
        System.out.println(a.subtract(b));
        System.out.println(a.multiply(b));
        BigInteger[] temp = a.divideAndRemainder(b);
        System.out.println(temp[0]);
        System.out.println(temp[1]);
    }
}