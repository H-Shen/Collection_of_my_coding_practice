// https://open.kattis.com/problems/batmanacci
//
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Batmanacci {

    public static final int OFFSET = 3;

    public static final int LOWER_BOUND = 2;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br    = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out   = new PrintWriter(new OutputStreamWriter(System.out));
        String[]       input = br.readLine().split(" ");
        int            n     = Integer.parseInt(input[0]);
        BigInteger     k     = new BigInteger(input[1]);

        ArrayList<BigInteger> tempArray = new ArrayList<>();
        tempArray.add(BigInteger.ZERO);
        tempArray.add(BigInteger.ONE);
        for (int i = 0; i < n + OFFSET; ++i) {
            tempArray.add(tempArray.get(tempArray.size() - 2).add(tempArray.get(tempArray.size() - 1)));
        }
        while (n > LOWER_BOUND) {
            if (k.compareTo(tempArray.get(n - LOWER_BOUND)) <= 0) {
                n -= LOWER_BOUND;
            } else {
                k = k.subtract(tempArray.get(n - LOWER_BOUND));
                --n;
            }
        }

        // output
        if (n == 1) {
            out.println('N');
        } else {
            out.println('A');
        }
        out.flush();
    }
}
