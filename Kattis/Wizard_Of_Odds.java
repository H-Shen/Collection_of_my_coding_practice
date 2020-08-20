// https://open.kattis.com/problems/wizardofodds
//
import java.io.*;
import java.math.BigInteger;

public class Wizard_Of_Odds {

    public static final BigInteger TWO = new BigInteger("2");

    public static final BigInteger LOWER_BOUND = new BigInteger("340");

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br    = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out   = new PrintWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        BigInteger n = new BigInteger(input[0]);
        BigInteger k = new BigInteger(input[1]);

        // output
        if (k.compareTo(LOWER_BOUND) >= 0) {
            out.println("Your wish is granted!");
            return;
        }
        if (TWO.pow(k.intValue()).compareTo(n) >= 0) {
            out.println("Your wish is granted!");
        } else {
            out.println("You will become a flying monkey!");
        }
        out.flush();
    }
}
