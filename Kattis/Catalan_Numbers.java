// https://open.kattis.com/problems/catalan
//
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Catalan_Numbers {

    public static ArrayList<BigInteger> C = new ArrayList<>();
    public static final int MAXN = 5005;

    public static void main(String[] args) {

        // pre
        BigInteger n = BigInteger.ONE;
        BigInteger two = new BigInteger("2");
        C.add(BigInteger.ONE);
        C.add(BigInteger.ONE);
        while (C.size() < MAXN) {
            C.add(n.multiply(two).add(BigInteger.ONE).multiply(two).multiply(C.get(C.size() - 1)).divide(n.add(two)));
            n = n.add(BigInteger.ONE);
        }

        // input
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        // output
        for (int i = 0; i < t; ++i) {
            System.out.println(C.get(in.nextInt()));
        }
    }
}
