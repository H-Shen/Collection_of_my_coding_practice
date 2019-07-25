import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in  = new Scanner(System.in);
        int     n   = in.nextInt();
        int[]   A   = new int[n];
        int[]   Sum = new int[n];
        int     sum = 0;
        for (int i = 0; i < n; ++i) {
            A[i] = in.nextInt();
            sum += A[i];
            Sum[i] = sum;
        }

        int tempSum;
        int counter = 0;
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                if (start == end) {
                    tempSum = A[start];
                } else if (start == 0) {
                    tempSum = Sum[end];
                } else {
                    tempSum = Sum[end] - Sum[start - 1];
                }
                if (tempSum < 0) {
                    ++counter;
                }
            }
        }
        System.out.println(counter);
    }
}

