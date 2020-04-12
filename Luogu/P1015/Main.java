import java.math.BigInteger;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    public static final BigInteger                     SIXTEEN      = new BigInteger("16");
    public static final HashMap<BigInteger, String>    CONVERT      = new HashMap<BigInteger, String>() {
        {
            put(new BigInteger("10"), "A");
            put(new BigInteger("11"), "B");
            put(new BigInteger("12"), "C");
            put(new BigInteger("13"), "D");
            put(new BigInteger("14"), "E");
            put(new BigInteger("15"), "F");
        }
    };
    public static final HashMap<Character, BigInteger> CONVERT_REV  = new HashMap<Character, BigInteger>() {
        {
            put('A', new BigInteger("10"));
            put('B', new BigInteger("11"));
            put('C', new BigInteger("12"));
            put('D', new BigInteger("13"));
            put('E', new BigInteger("14"));
            put('F', new BigInteger("15"));
            // Dont forget to cover the lowercase.
            put('a', new BigInteger("10"));
            put('b', new BigInteger("11"));
            put('c', new BigInteger("12"));
            put('d', new BigInteger("13"));
            put('e', new BigInteger("14"));
            put('f', new BigInteger("15"));
        }
    };
    public static final int                            MAXIMAL_STEP = 30;

    public static String convertToOtherBase(BigInteger decimal, BigInteger base) {
        if (base.compareTo(BigInteger.TEN) == 0) {
            return decimal.toString();
        }
        StringBuilder sb = new StringBuilder();
        while (decimal.compareTo(BigInteger.ZERO) > 0) {
            BigInteger[] temp = decimal.divideAndRemainder(base);
            if (base.compareTo(SIXTEEN) == 0 && temp[1].compareTo(BigInteger.TEN) >= 0) {
                sb.append(CONVERT.get(temp[1]));
            } else {
                sb.append(temp[1].toString());
            }
            decimal = temp[0];
        }
        sb.reverse();
        return sb.toString();
    }

    public static boolean isPalindrome(String sb) {
        String temp = removeHeadingZeros(sb);
        StringBuilder sbCopy = new StringBuilder(temp);
        sbCopy.reverse();
        return temp.equals(removeHeadingZeros(sbCopy.toString()));
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

    public static String getReverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        return sb.toString();
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

    public static void main(String[] args) {

        Scanner    in       = new Scanner(System.in);
        BigInteger base     = in.nextBigInteger();
        BigInteger sum;
        String m = in.next();
        String mReverse = getReverse(m);
        if (m.length() != mReverse.length()) {
            System.out.println("Impossible!");
            return;
        }
        for (int steps = 1; steps <= MAXIMAL_STEP; ++steps) {
            sum = convertToDecimal(m, base).add(convertToDecimal(mReverse, base));
            if (isPalindrome(convertToOtherBase(sum, base))) {
                System.out.println("STEP=" + steps);
                return;
            }
            m = convertToOtherBase(sum, base);
            mReverse = getReverse(m);
        }
        System.out.println("Impossible!");
    }
}