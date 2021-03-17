import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

    private static final int          MAXN           = 65;
    private static final BigInteger   THREE          = new BigInteger("3");
    private static final BigInteger   TWO            = new BigInteger("2");
    private static final BigInteger[] POWER_OF_THREE = new BigInteger[MAXN];

    public static String getBinaryString(BigInteger n) {
        StringBuilder stringBuilder = new StringBuilder();
        while (n.compareTo(BigInteger.ZERO) > 0) {
            if (n.mod(TWO).compareTo(BigInteger.ZERO) == 0) {
                stringBuilder.append('0');
            } else {
                stringBuilder.append('1');
            }
            n = n.divide(TWO);
        }
        return stringBuilder.toString();
    }

    public static ArrayList<BigInteger> solve(BigInteger n) {
        ArrayList<BigInteger> result = new ArrayList<>();
        if (n.equals(BigInteger.ZERO)) {
            return result;
        }
        String string = getBinaryString(n);
        for (int i = 0; i < string.length(); ++i) {
            if (string.charAt(i) == '1') {
                result.add(POWER_OF_THREE[i]);
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        // pre
        POWER_OF_THREE[0] = BigInteger.ONE;
        for (int i = 1; i < MAXN; ++i) {
            POWER_OF_THREE[i] = POWER_OF_THREE[i - 1].multiply(THREE);
        }

        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        while (true) {
            BigInteger n = new BigInteger(br.readLine());
            if (n.equals(BigInteger.ZERO)) {
                break;
            }
            n = n.subtract(BigInteger.ONE);
            ArrayList<BigInteger> output = solve(n);
            out.print("{ ");
            if (!output.isEmpty()) {
                for (int i = 0; i < output.size() - 1; ++i) {
                    out.print(output.get(i) + ", ");
                }
                out.print(output.get(output.size() - 1) + " ");
            }
            out.println('}');
        }
        out.flush();
    }
}