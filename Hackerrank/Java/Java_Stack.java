import java.util.Scanner;
import java.util.Stack;

class Solution {

    private static boolean isValid(String s) {
        int              len = s.length();
        char             cmp;
        Stack<Character> A   = new Stack<>();
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '[' || s.charAt(i) == '{' || s.charAt(i) == '(') {
                A.push(s.charAt(i));
            } else {
                if (A.isEmpty()) {
                    return false;
                } else {
                    cmp = A.peek();
                    if ((s.charAt(i) == ')' && cmp != '(') || (s.charAt(i) == '}' && cmp != '{') || (s.charAt(i) == ']' && cmp != '[')) {
                        return false;
                    }
                    A.pop();
                }
            }
            if (i == len - 1 && !A.isEmpty()) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] argh) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String input = sc.next();
            //Complete the code
            System.out.println(isValid(input));
        }

    }
}
