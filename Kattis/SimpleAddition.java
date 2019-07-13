// https://open.kattis.com/problems/simpleaddition

import java.util.Scanner;

public class SimpleAddition {

    public static void main(String[] arg) {
        Scanner in = new Scanner(System.in);
        System.out.println(in.nextBigInteger().add(in.nextBigInteger()));
    }
}
