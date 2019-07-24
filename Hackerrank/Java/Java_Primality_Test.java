import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    private static final Scanner scanner   = new Scanner(System.in);

    private static final int     CERTAINTY = 100;

    public static void main(String[] args) {
        String n = scanner.nextLine();
        if (new BigInteger(n).isProbablePrime(CERTAINTY)) {
            System.out.println("prime");
        } else {
            System.out.println("not prime");
        }
        scanner.close();
    }
}
