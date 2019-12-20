// https://www.nowcoder.com/practice/113d0e19fa1841c2a8baf80585380734

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    private static final Set<Character> charSet = new HashSet<Character>() {{
        add('[');
        add(']');
        add('\\');
        add('^');
        add('_');
        add('’');
    }};

    public static void main(String[] arg) {

        Scanner in = new Scanner(System.in);
        String  s  = in.next();
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isDigit(s.charAt(i))) {
                continue;
            }
            if (Character.isLetter(s.charAt(i)) || charSet.contains(s.charAt(i))) {
                System.out.print(s.charAt(i));
            } else {
                System.out.print("^");
            }
        }
        System.out.println();
    }
}
