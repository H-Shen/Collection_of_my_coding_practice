// https://open.kattis.com/problems/wizardofodds
//
import java.math.BigInteger;
import java.util.Scanner;

public class WizardOfOdds {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger TWO = new BigInteger("2");
        BigInteger n = in.nextBigInteger();
        BigInteger k = in.nextBigInteger();
        if (k.compareTo(new BigInteger("340")) >= 0) {
            System.out.println("Your wish is granted!");
            return;
        }
        if (TWO.pow(k.intValue()).compareTo(n) >= 0) {
            System.out.println("Your wish is granted!");
        } else {
            System.out.println("You will become a flying monkey!");
        }
    }
}
