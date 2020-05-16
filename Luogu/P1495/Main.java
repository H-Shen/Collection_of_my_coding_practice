import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader        br     = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter           out    = new PrintWriter(new OutputStreamWriter(System.out));
        ArrayList<BigInteger> A      = new ArrayList<>();
        ArrayList<BigInteger> N      = new ArrayList<>();
        int                   number = Integer.parseInt(br.readLine());
        BigInteger            a, n;
        for (int i = 0; i < number; ++i) {
            String[] temp = br.readLine().split(" ");
            n = new BigInteger(temp[0]);
            a = new BigInteger(temp[1]);
            A.add(a);
            N.add(n);
        }
        BigInteger n_ = BigInteger.ONE;
        for (BigInteger i : N) {
            n_ = n_.multiply(i);
        }
        ArrayList<BigInteger> M = new ArrayList<>();
        for (BigInteger i : N) {
            M.add(n_.divide(i));
        }
        ArrayList<BigInteger> M_Rev = new ArrayList<>();
        for (int i = 0; i < M.size(); ++i) {
            M_Rev.add(M.get(i).modInverse(N.get(i)));
        }
        ArrayList<BigInteger> C = new ArrayList<>();
        for (int i = 0; i < M.size(); ++i) {
            C.add(M.get(i).multiply(M_Rev.get(i)));
        }
        BigInteger ans = BigInteger.ZERO;
        for (int i = 0; i < M.size(); ++i) {
            ans = ans.add(A.get(i).multiply(C.get(i)));
        }
        ans = ans.mod(n_);
        // output
        out.println(ans);
        out.flush();
    }
}