import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = "";
        String largest = "";

        // Complete the function
        // 'smallest' must be the lexicographically smallest substring of length 'k'
        // 'largest' must be the lexicographically largest substring of length 'k'
        String temp;
        boolean firstItem = true;
        for (int i = 0; i < s.length(); ++i) {
            if (i + k > s.length()) {
                break;
            }
            temp = s.substring(i, i + k);
            if (firstItem) {
                smallest = temp;
                largest = temp;
                firstItem = false;
            } else {
                if (smallest.compareTo(temp) > 0) {
                    smallest = temp;
                }
                if (largest.compareTo(temp) < 0) {
                    largest = temp;
                }
            }
        }
        return smallest + "\n" + largest;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();

        System.out.println(getSmallestAndLargest(s, k));
    }
}