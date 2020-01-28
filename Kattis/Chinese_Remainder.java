// https://open.kattis.com/problems/chineseremainder
//
import java.math.BigInteger;
import java.util.Scanner;

public class Chinese_Remainder {

    public static void main(String[] args)  {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        BigInteger a;
        BigInteger n;
        BigInteger n_rev;
        BigInteger b;
        BigInteger m;
        BigInteger m_rev;
        BigInteger k;
        BigInteger c;
        BigInteger c1;
        BigInteger c2;
        for (int i = 0; i < T; ++i) {
            // input
            a = in.nextBigInteger();
            n = in.nextBigInteger();
            b = in.nextBigInteger();
            m = in.nextBigInteger();
            // calculation
            k = m.multiply(n);
            m_rev = m.modInverse(n);
            c1 = m.multiply(m_rev);
            c1 = c1.multiply(a);
            n_rev = n.modInverse(m);
            c2 = n.multiply(n_rev);
            c2 = c2.multiply(b);
            c = c1.add(c2).mod(k);
            // output
            System.out.println(c + " " + k);
        }
    }
}
