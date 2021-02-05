// https://open.kattis.com/problems/digitdivision

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Digit_Division {


    private static final BigInteger MOD = new BigInteger("1000000007");

    private static final BigInteger TWO = new BigInteger("2");

    public static void main(String[] args) throws IOException {

        // pre
        ArrayList<BigInteger> arrayList = new ArrayList<>();
        arrayList.add(BigInteger.ZERO);
        for (int i = 1; i < 10; ++i) {
            arrayList.add(arrayList.get(i - 1).add(BigInteger.ONE));
        }

        BufferedReader br      = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out     = new PrintWriter(new OutputStreamWriter(System.out));
        String[]       s       = br.readLine().split(" ");
        int            n       = Integer.parseInt(s[0]);
        BigInteger     m       = new BigInteger(s[1]);
        String         input   = br.readLine();
        BigInteger     par     = BigInteger.ZERO;
        BigInteger     current = null;
        for (int i = 0; i < n; ++i) {
            if (current == null) {
                current = arrayList.get(input.charAt(i) - '0');
            } else {
                current = current.multiply(BigInteger.TEN).add(arrayList.get(input.charAt(i) - '0'));
            }
            if (current.mod(m).equals(BigInteger.ZERO)) {
                par = par.add(BigInteger.ONE);
                current = null;
            }
        }
        if (current != null && !current.mod(m).equals(BigInteger.ZERO)) {
            out.println(0);
        }
        else if (par.equals(BigInteger.ZERO)) {
            out.println(0);
        }
        else {
            out.println(TWO.modPow(par.subtract(BigInteger.ONE), MOD));
        }
        out.flush();
    }
}
