// https://www.nowcoder.com/practice/dab59997905b4459a42587fece8a75f4

import java.util.*;

public class FirstRepeat {
    public char findFirstRepeat(String A, int n) {
        // write code here
        HashSet<Character> table = new HashSet<>();
        char result = '\0';
        for (int i = 0; i < A.length(); ++i) {
            if (table.contains(A.charAt(i))) {
                result = A.charAt(i);
                break;
            } else {
                table.add(A.charAt(i));
            }
        }
        return result;
    }
}