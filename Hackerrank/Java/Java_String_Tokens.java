import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String  s    = scan.nextLine();
        // Write your code here.
        String            pattern = "[A-Za-z]+";
        Pattern           r       = Pattern.compile(pattern);
        Matcher           m       = r.matcher(s);
        int               counter = 0;
        ArrayList<String> result  = new ArrayList<>();
        while (m.find()) {
            result.add(m.group());
            ++counter;
        }
        System.out.println(counter);
        for (String i : result) {
            System.out.println(i);
        }
        scan.close();
    }
}

