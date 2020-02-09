import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        BigInteger base = new BigInteger("2");
        System.out.println(base.pow(n).subtract(BigInteger.ONE));
    }
}