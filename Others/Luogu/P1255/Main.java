import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static final int MAX = 5005;

    public static void main(String[] args) {
        // pre
        ArrayList<BigInteger> arr = new ArrayList<>();
        arr.add(BigInteger.ZERO);
        arr.add(BigInteger.ONE);
        arr.add(new BigInteger("2"));
        while (arr.size() < MAX) {
            BigInteger a = arr.get(arr.size() - 1);
            BigInteger b = arr.get(arr.size() - 2);
            arr.add(a.add(b));
        }
        Scanner in = new Scanner(System.in);
        System.out.println(arr.get(in.nextInt()));
    }
}