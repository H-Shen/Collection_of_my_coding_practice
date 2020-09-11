import java.io.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br   = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out  = new PrintWriter(new OutputStreamWriter(System.out));
        int            n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; ++i) {
            String[] arguments = br.readLine().split(" ");
            BigInteger a = new BigInteger(arguments[0]);
            BigInteger b = new BigInteger(arguments[1]);
            BigInteger temp;
            int m = Integer.parseInt(arguments[2]);
            for (int j = 0; j < m; ++j) {
                temp = b;
                b = b.add(a);
                a = temp;
            }
            out.println(a);
        }
        out.flush();
    }
}