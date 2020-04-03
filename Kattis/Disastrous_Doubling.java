// https://open.kattis.com/problems/disastrousdoubling
//
import java.math.BigInteger;
import java.util.Scanner;

public class Disastrous_Doubling {

    private static final BigInteger MOD = new BigInteger("1000000007");

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        BigInteger a = BigInteger.ONE;
        BigInteger val;
        boolean haveAns = true;
        for (int i = 0; i < n; ++i) {
            val = in.nextBigInteger();
            a = a.multiply(new BigInteger("2")).subtract(val);
            if (a.compareTo(BigInteger.ZERO) < 0) {
                haveAns = false;
                System.out.println("error");
                break;
            }
        }
        if (haveAns) {
            System.out.println(a.mod(MOD));
        }
    }
}
