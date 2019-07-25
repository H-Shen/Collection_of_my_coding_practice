import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static int B;
    private static int H;
    private static boolean flag = true;
    static {
        Scanner in = new Scanner(System.in);
        B = in.nextInt();
        H = in.nextInt();
        if (B <= 0 || H <= 0) {
            System.out.println("java.lang.Exception: Breadth and height must be positive");
            System.exit(0);
        }
    }

public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}

	}//end of main

}//end of class

