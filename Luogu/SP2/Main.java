import java.io.*;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) throws IOException {
        // input
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        int            t   = Integer.parseInt(br.readLine());
        BigInteger lowerBound, upperBound;
        for (int i = 0; i < t; ++i) {
            String[] temp = br.readLine().split(" ");
            lowerBound = new BigInteger(temp[0]);
            upperBound = new BigInteger(temp[1]);
            lowerBound = lowerBound.subtract(BigInteger.ONE);
            if (i != 0) {
                out.println();
            }
            while (true) {
                lowerBound = lowerBound.nextProbablePrime();
                if (lowerBound.compareTo(upperBound) > 0) {
                    break;
                }
                out.println(lowerBound);
            }
        }

        out.flush();
    }
}