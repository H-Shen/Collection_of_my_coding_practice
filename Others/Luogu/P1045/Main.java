import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static final BigInteger TWO    = new BigInteger("2");
    public static final BigInteger MOD    = new BigInteger("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    public static final int        LENGTH = 500;
    public static final int MAX_LINE_COLUMNS = 50;

    public static void main(String[] args) {
        Scanner in     = new Scanner(System.in);
        int     p      = in.nextInt();
        int     digits = (int) (p * Math.log10(2.0) + 1.0);
        BigInteger   P           = new BigInteger(String.valueOf(p));
        String        result     = TWO.modPow(P, MOD).subtract(BigInteger.ONE).mod(MOD).toString();
        StringBuilder sb         = new StringBuilder(result);
        StringBuilder headZeroes = new StringBuilder();
        int           totalLength = sb.length() + headZeroes.length();
        while (totalLength < LENGTH) {
            headZeroes.append('0');
            ++totalLength;
        }
        sb = headZeroes.append(sb);

        // output
        System.out.println(digits);
        for (int i = 0; i < sb.length(); ++i) {
            System.out.print(sb.charAt(i));
            if (i > 0 && (i+1) % MAX_LINE_COLUMNS == 0) {
                System.out.println();
            }
        }
    }

}