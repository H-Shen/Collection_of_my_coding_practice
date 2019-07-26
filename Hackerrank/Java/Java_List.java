import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner       in = new Scanner(System.in);
        int           n  = in.nextInt();
        List<Integer> L  = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            L.add(in.nextInt());
        }
        int    q = in.nextInt();
        String query;
        int    x, y;
        for (int i = 0; i < q; ++i) {
            query = in.next();
            switch (query) {
                case "Insert":
                    x = in.nextInt();
                    y = in.nextInt();
                    L.add(x, y);
                    break;
                case "Delete":
                    x = in.nextInt();
                    L.remove(x);
                    break;
                default:
                    break;
            }
        }
        boolean firstItem = true;
        for (Integer i : L) {
            if (firstItem) {
                firstItem = false;
            } else {
                System.out.print(" ");
            }
            System.out.print(i);
        }
        System.out.println();
    }
}

