import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] arg) {
        Scanner in = new Scanner(System.in);
        BigInteger n = in.nextBigInteger().add(BigInteger.ONE);
        BigInteger C_i_1 = BigInteger.ONE;
        BigInteger Four = new BigInteger("4");
        BigInteger Two = new BigInteger("2");
        BigInteger C_i = C_i_1;
        for (BigInteger i = BigInteger.ONE; i.compareTo(n) < 0; i = i.add(BigInteger.ONE)) {
            C_i = i.multiply(Four).subtract(Two).multiply(C_i_1).divide(i.add(BigInteger.ONE));
            C_i_1 = C_i;
        }
        System.out.println(C_i);
    }
}