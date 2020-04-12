import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static String Factorial(int n) {
        if (n <= 0) {
            return String.valueOf(1);
        }
        BigInteger m = BigInteger.ONE;
        for (int i = 1; i <= n; ++i) {
            m = m.multiply(new BigInteger(String.valueOf(i)));
        }
        return m.toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        String tempString;
        char a;
        for (int i = 0; i < t; ++i) {
            tempString = Factorial(in.nextInt());
            a = in.next().charAt(0);
            int counter = 0;
            for (int j = 0; j < tempString.length(); ++j) {
                if (tempString.charAt(j) == a) {
                    ++counter;
                }
            }
            System.out.println(counter);
        }
    }
}
