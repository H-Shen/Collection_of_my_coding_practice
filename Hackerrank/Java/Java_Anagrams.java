import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        // Complete the function
        a = a.toLowerCase();
        b = b.toLowerCase();
        int length = 26;
        int[] aFreq = new int[length];
        for (int i = 0; i < a.length(); ++i) {
            ++aFreq[a.charAt(i) - 'a'];
        }
        int[] bFreq = new int[length];
        for (int i = 0; i < b.length(); ++i) {
            ++bFreq[b.charAt(i) - 'a'];
        }
        for (int i = 0; i < length; ++i) {
            if (aFreq[i] != bFreq[i]) {
                return false;
            }
        }
        return true;
    }

  public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
