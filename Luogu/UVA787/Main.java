import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

// Maximum Sub-sequence Product
public class Main {

    public static BigInteger maxBigInteger(BigInteger... args) {
        if (args.length == 0) {
            throw new IllegalArgumentException();
        }
        BigInteger result = args[0];
        for (int i = 1; i < args.length; ++i) {
            result = result.max(args[i]);
        }
        return result;
    }

    public static BigInteger minBigInteger(BigInteger... args) {
        if (args.length == 0) {
            throw new IllegalArgumentException();
        }
        BigInteger result = args[0];
        for (int i = 1; i < args.length; ++i) {
            result = result.min(args[i]);
        }
        return result;
    }

    public static BigInteger solve(ArrayList<BigInteger> dp) {
        if (dp.isEmpty()) {
            return BigInteger.ZERO;
        }
        if (dp.size() == 1) {
            return dp.get(0);
        }
        BigInteger maxProduct = dp.get(0);
        BigInteger minProduct = dp.get(0);
        BigInteger result     = dp.get(0);
        for (int i = 1; i < dp.size(); ++i) {
            BigInteger temp0 = maxProduct.multiply(dp.get(i));
            BigInteger temp1 = minProduct.multiply(dp.get(i));
            maxProduct = maxBigInteger(temp0, temp1, dp.get(i));
            minProduct = minBigInteger(temp0, temp1, dp.get(i));
            result = maxBigInteger(result, maxProduct);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String         input;
        while ((input = br.readLine()) != null) {
            String[]              arguments = input.split(" ");
            ArrayList<BigInteger> dp        = new ArrayList<>();
            for (int i = 0; i < arguments.length - 1; ++i) {
                dp.add(new BigInteger(arguments[i]));
            }
            out.println(solve(dp));
        }
        out.flush();
    }
}