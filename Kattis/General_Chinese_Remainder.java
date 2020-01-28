// https://open.kattis.com/problems/generalchineseremainder
//
import java.math.BigInteger;
import java.util.Scanner;

class Pair<K, V> {
    K fst;
    V snd;
    public Pair(K fst, V snd) {
        this.fst = fst;
        this.snd = snd;
    }
}

public class General_Chinese_Remainder {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        BigInteger a;
        BigInteger n;
        BigInteger b;
        BigInteger m;
        for (int i = 0; i < T; ++i) {
            // input
            a = in.nextBigInteger();
            n = in.nextBigInteger();
            b = in.nextBigInteger();
            m = in.nextBigInteger();
            // Case 1: gcd(m, n) = 1
            if (n.gcd(m).compareTo(BigInteger.ONE) == 0) {
                Pair<BigInteger, BigInteger> tempPair = solve0(a, n, b, m);
                System.out.println(tempPair.fst + " " + tempPair.snd);
            }
            // Case 2: gcd(m, n) != 1
            else {
                // Subcase 1: there does not exist an integer k such that (b - a) != gcd(m, n) * k
                BigInteger temp = b.subtract(a);
                if (temp.compareTo(BigInteger.ZERO) < 0) {
                    temp = temp.negate();
                }
                if (temp.mod(m.gcd(n)).compareTo(BigInteger.ZERO) == 0) {
                    Pair<BigInteger, BigInteger> tempPair = solve1(a, n, b, m);
                    System.out.println(tempPair.fst + " " + tempPair.snd);
                } else {
                    System.out.println("no solution");
                }
            }
        }
    }

    public static Pair<BigInteger, BigInteger> solve0(BigInteger a, BigInteger n, BigInteger b, BigInteger m)  {
        BigInteger n_rev;
        BigInteger m_rev;
        BigInteger k;
        BigInteger c;
        BigInteger c1;
        BigInteger c2;
        // calculation
        k = m.multiply(n);
        m_rev = m.modInverse(n);
        c1 = m.multiply(m_rev);
        c1 = c1.multiply(a);
        n_rev = n.modInverse(m);
        c2 = n.multiply(n_rev);
        c2 = c2.multiply(b);
        c = c1.add(c2).mod(k);
        // return the result
        return new Pair<>(c, k);
    }

    public static Pair<BigInteger, BigInteger> solve1(BigInteger a, BigInteger n, BigInteger b, BigInteger m) {
        BigInteger g = n.gcd(m);
        BigInteger n_lcm_m = n.multiply(m).divide(g);
        BigInteger n_div_gcd = n.divide(g);
        BigInteger m_div_gcd = m.divide(g);
        BigInteger result;

        // Case 1: b >= a
        if (b.compareTo(a) >= 0) {
            BigInteger x    = n_div_gcd.modInverse(m_div_gcd);
            BigInteger p    = x.multiply(b.subtract(a)).divide(g);
            result = n.multiply(p).add(a);
            result = result.mod(n_lcm_m);
        }
        // Case 2: b < a
        else {
            BigInteger x = m_div_gcd.modInverse(n_div_gcd);
            BigInteger q = x.multiply(a.subtract(b)).divide(g);
            result = m.multiply(q).add(b);
            result = result.mod(n_lcm_m);
        }
        return new Pair<>(result, n_lcm_m);
    }
}
