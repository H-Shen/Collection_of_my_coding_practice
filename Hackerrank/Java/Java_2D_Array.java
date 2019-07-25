import java.util.Scanner;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int maxVal = Integer.MIN_VALUE;
        int sum;
        for (int i = 0; i <= 3; ++i) {
            for (int j = 0; j <= 3; ++j) {
                try {
                    sum = 0;
                    sum += arr[i][j];
                    sum += arr[i][j + 1];
                    sum += arr[i][j + 2];
                    sum += arr[i + 1][j + 1];
                    sum += arr[i + 2][j + 1];
                    sum += arr[i + 2][j];
                    sum += arr[i + 2][j + 2];
                    if (sum > maxVal) {
                        maxVal = sum;
                    }
                } catch (Exception ex) {
                }
            }
        }
        System.out.println(maxVal);

        scanner.close();
    }
}
