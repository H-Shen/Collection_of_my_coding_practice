//Complete this code or write your own from scratch

import java.util.HashMap;
import java.util.Scanner;

class Solution {
    public static void main(String[] argh) {
        Scanner                  in = new Scanner(System.in);
        HashMap<String, Integer> A  = new HashMap<>();
        int                      n  = in.nextInt();
        in.nextLine();
        for (int i = 0; i < n; i++) {
            String name  = in.nextLine();
            int    phone = in.nextInt();
            A.put(name, phone);
            in.nextLine();
        }
        while (in.hasNext()) {
            String s = in.nextLine();
            if (A.containsKey(s)) {
                System.out.println(s + "=" + A.get(s));
            } else {
                System.out.println("Not found");
            }
        }
    }
}
