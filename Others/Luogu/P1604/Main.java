import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    private static final int MAX = 2005;

    public static void main(String[] args) {
        // input
        Scanner in = new Scanner(System.in);
        BigInteger base = in.nextBigInteger();
        // pre
        ArrayList<BigInteger> pre = new ArrayList<>();
        pre.add(BigInteger.ONE);
        while (pre.size() < MAX) {
            BigInteger temp = pre.get(pre.size() - 1).multiply(base);
            pre.add(temp);
        }
        HashMap<Character, Integer> hashMap = new HashMap<>();
        HashMap<Integer, Character> hashMapRev = new HashMap<>();
        String tempString = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < tempString.length(); ++i) {
            hashMap.put(tempString.charAt(i), i);
            hashMapRev.put(i, tempString.charAt(i));
        }
        // input
        String a = in.next();
        BigInteger a_int = BigInteger.ZERO;
        for (int i = 0; i < a.length(); ++i) {
            a_int =
                    a_int.add(new BigInteger(String.valueOf(hashMap.get(a.charAt(i)))).multiply(pre.get(a.length() - i - 1)));
        }
        String b = in.next();
        BigInteger b_int = BigInteger.ZERO;
        for (int i = 0; i < b.length(); ++i) {
            b_int = b_int.add(new BigInteger(String.valueOf(hashMap.get(b.charAt(i)))).multiply(pre.get(b.length() - i - 1)));
        }
        BigInteger sum = a_int.add(b_int);
        StringBuilder sb = new StringBuilder();
        while (sum.compareTo(BigInteger.ZERO) > 0) {
            sb.append(hashMapRev.get(sum.mod(base).intValue()));
            sum = sum.divide(base);
        }
        sb.reverse();
        System.out.println(sb);
    }
}

