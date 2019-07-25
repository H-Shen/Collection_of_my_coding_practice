import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner                       in = new Scanner(System.in);
        ArrayList<ArrayList<Integer>> A  = new ArrayList<>();
        int                           n  = in.nextInt();
        for (int i = 0; i < n; ++i) {
            int                length    = in.nextInt();
            ArrayList<Integer> tempArray = new ArrayList<>();
            for (int j = 0; j < length; ++j) {
                tempArray.add(in.nextInt());
            }
            A.add(tempArray);
        }
        n = in.nextInt();
        for (int i = 0; i < n; ++i) {
            try {
                System.out.println(A.get(in.nextInt() - 1).get(in.nextInt() - 1));
            } catch (Exception ex) {
                System.out.println("ERROR!");
            }
        }
    }
}

