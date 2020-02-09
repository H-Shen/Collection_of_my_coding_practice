import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // input
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        // output
        System.out.println(a.divide(b));
    }
}