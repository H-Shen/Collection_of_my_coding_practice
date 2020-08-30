import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static final BigInteger UPPER_BOUND = BigInteger.TEN.pow(101);

    public static ArrayList<BigInteger> L = new ArrayList<>();

    public static int lowerBound(BigInteger a) {
        if (a.compareTo(L.get(0)) < 0) {
            a = L.get(0);
        } else if (a.compareTo(L.get(L.size() - 1)) > 0) {
            a = L.get(L.size() - 1);
        }
        int aPos;
        int temp = Collections.binarySearch(L, a);
        if (temp >= 0) {
            aPos = temp;
        } else {
            aPos = -temp - 1;
        }
        return aPos;
    }

    public static int solve(BigInteger a, BigInteger b) {
        int counter = 0;
        int aPos    = lowerBound(a);
        while (L.get(aPos).compareTo(b) <= 0) {
            ++counter;
            ++aPos;
        }
        return counter;
    }

    public static void main(String[] args) throws IOException {
        // pre
        L.add(BigInteger.ONE);
        L.add(new BigInteger("2"));
        while (L.get(L.size() - 1).compareTo(UPPER_BOUND) < 0) {
            L.add(L.get(L.size() - 1).add(L.get(L.size() - 2)));
        }
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        while (true) {
            String[] input = br.readLine().split(" ");
            if (input[0].compareTo("0") == 0 && input[1].compareTo("0") == 0) {
                break;
            }
            out.println(solve(new BigInteger(input[0]), new BigInteger(input[1])));
        }
        out.flush();
    }
}