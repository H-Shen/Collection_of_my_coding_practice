// https://open.kattis.com/problems/checkingforcorrectness
//
import java.math.BigInteger;
import java.util.Scanner;

public class Checking_For_Correctness {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a;
        BigInteger b;
        BigInteger c;
        BigInteger m = new BigInteger("10000");
        String op;
        while (in.hasNextBigInteger()) {
            a = in.nextBigInteger();
            op = in.next();
            b = in.nextBigInteger();
            switch (op) {
                case "+":
                    c = a.add(b).mod(m);
                    break;
                case "^":
                    c = a.modPow(b, m);
                    break;
                default:
                    c = a.multiply(b).mod(m);
                    break;
            }
            System.out.println(c);
        }
    }
}
