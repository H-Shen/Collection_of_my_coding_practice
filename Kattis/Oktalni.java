// https://open.kattis.com/problems/oktalni
//
import java.math.BigInteger;
import java.util.Scanner;

public class Oktalni {

    public static final BigInteger TWO = new BigInteger("2");
    public static final int RADIX = 8;

    public static BigInteger convertToDecimal(String number) {
        BigInteger temp = BigInteger.ZERO;
        for (int i = number.length() - 1; i >= 0; --i) {
            BigInteger val = TWO.pow(number.length() - 1 - i);
            BigInteger tempNumber = new BigInteger("" + number.charAt(i));
            temp = temp.add(tempNumber.multiply(val));
        }
        return temp;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String binary = in.next();
        System.out.println(convertToDecimal(binary).toString(RADIX));
    }
}
