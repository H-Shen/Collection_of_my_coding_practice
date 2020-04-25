import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static final HashMap<BigInteger, String> CONVERT = new HashMap<>();
    public static final HashMap<Character, BigInteger> CONVERT_REV  = new HashMap<>();

    public static String convertToOtherBase(BigInteger decimal, BigInteger base) {
        if (base.compareTo(BigInteger.TEN) == 0) {
            return decimal.toString();
        }
        StringBuilder sb = new StringBuilder();
        while (decimal.compareTo(BigInteger.ZERO) > 0) {
            BigInteger[] temp = decimal.divideAndRemainder(base);
            if (temp[1].compareTo(BigInteger.TEN) >= 0) {
                sb.append(CONVERT.get(temp[1]));
            } else {
                sb.append(temp[1].toString());
            }
            decimal = temp[0];
        }
        sb.reverse();
        return sb.toString();
    }

    public static BigInteger convertToDecimal(String number, BigInteger base) {
        if (base.compareTo(BigInteger.TEN) == 0) {
            return new BigInteger(number);
        }
        BigInteger temp = BigInteger.ZERO;
        for (int i = number.length() - 1; i >= 0; --i) {
            BigInteger val = base.pow(number.length() - 1 - i);
            if (CONVERT_REV.containsKey(number.charAt(i))) {
                temp = temp.add(CONVERT_REV.get(number.charAt(i)).multiply(val));
            } else {
                BigInteger tempNumber = new BigInteger("" + number.charAt(i));
                temp = temp.add(tempNumber.multiply(val));
            }
        }
        return temp;
    }

    public static String removeHeadingZeros(String s) {
        if (s.length() > 1 && s.charAt(0) == '0') {
            Deque<Character> deque = new LinkedList<>();
            for (int i = 0; i < s.length(); ++i) {
                deque.addLast(s.charAt(i));
            }
            while (deque.size() > 1 && deque.getFirst().compareTo('0') == 0) {
                deque.pollFirst();
            }
            StringBuilder result = new StringBuilder();
            while (!deque.isEmpty()) {
                result.append(deque.pollFirst());
            }
            return result.toString();
        }
        return s;
    }

    public static void main(String[] args) throws IOException {

        // pre
        StringBuilder sb = new StringBuilder("a");
        for (int i = 10; i <= 35; ++i) {
            CONVERT.put(new BigInteger(Integer.toString(i)), sb.toString());
            sb.setCharAt(0, (char) (sb.charAt(0) + 1));
        }
        char tempChar = 'a';
        for (int i = 10; i <= 35; ++i) {
            CONVERT_REV.put(tempChar, new BigInteger(Integer.toString(i)));
            ++tempChar;
        }

        // input
        BufferedReader br  =new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));

        BigInteger base     = new BigInteger(br.readLine());
        String a = removeHeadingZeros(br.readLine());
        String b = removeHeadingZeros(br.readLine());
        
        // output
        out.println(convertToOtherBase(convertToDecimal(a, base).add(convertToDecimal(b, base)), base));
        out.flush();
    }
}