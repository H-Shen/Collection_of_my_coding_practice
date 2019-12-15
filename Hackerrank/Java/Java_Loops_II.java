import java.util.*;

class Solution{

    private static int powerOfTwo(int n) {
        if (n <= 0) {
            return 1;
        }
        int result = 1;
        for (int i = 0; i < n; ++i) {
            result *= 2;
        }
        return result;
    }

    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            boolean firstItem = true;
            for (int k = 1; k <= n; ++k) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    System.out.print(" ");
                }
                System.out.print(a + (powerOfTwo(k) - 1) * b);
            }
            System.out.println();
        }
        in.close();
    }
}

