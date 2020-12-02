import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

    public static final int MAX_LENGTH = 10005;
    public static ArrayList<BigInteger> Lucas = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // write your code here
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        // pre
        Lucas.add(new BigInteger("2"));
        Lucas.add(new BigInteger("1"));
        while (Lucas.size() < MAX_LENGTH) {
            Lucas.add(Lucas.get(Lucas.size() - 1).add(Lucas.get(Lucas.size() - 2)));
        }
        // input
        String s;
        while ((s = br.readLine()) != null) {
            out.println(Lucas.get(Integer.parseInt(s)));
        }
        out.flush();
    }
}
