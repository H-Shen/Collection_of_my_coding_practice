import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

    public static final int SIZE = 5005;

    public static void main(String[] args) throws IOException {
        // input
        BufferedReader        br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter           out = new PrintWriter(new OutputStreamWriter(System.out));
        ArrayList<BigInteger> Fib = new ArrayList<>();
        Fib.add(BigInteger.ZERO);
        Fib.add(BigInteger.ONE);
        while (Fib.size() < SIZE) {
            Fib.add(Fib.get(Fib.size() - 1).add(Fib.get(Fib.size() - 2)));
        }
        String input;
        while ((input = br.readLine()) != null) {
            out.println("The Fibonacci number for " + input + " is " + Fib.get(Integer.parseInt(input)));
        }
        out.flush();
    }
}