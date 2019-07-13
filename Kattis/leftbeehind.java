// https://open.kattis.com/problems/leftbeehind

import java.util.Scanner;

public class leftbeehind {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        while (true) {
            int firstNum  = scan.nextInt();
            int secondNum = scan.nextInt();
            if ((firstNum == 0) && (secondNum == 0)) {
                break;
            }
            if (firstNum + secondNum == 13) {
                System.out.println("Never speak again.");
            } else if (firstNum > secondNum) {
                System.out.println("To the convention.");
            } else if (firstNum == secondNum) {
                System.out.println("Undecided.");
            } else {
                System.out.println("Left beehind.");
            }
        }
    }
}
