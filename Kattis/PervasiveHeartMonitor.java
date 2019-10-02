// https://open.kattis.com/problems/pervasiveheartmonitor
//
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class PervasiveHeartMonitor {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()) {
            String[]              s    = in.nextLine().split(" ");
            ArrayList<String>     name = new ArrayList<>();
            ArrayList<BigDecimal> data = new ArrayList<>();
            for (String word : s) {
                boolean hasLetter = false;
                for (int j = 0; j < word.length(); ++j) {
                    if (Character.isLetter(word.charAt(j))) {
                        hasLetter = true;
                        break;
                    }
                }
                if (hasLetter) {
                    name.add(word);
                } else {
                    data.add(new BigDecimal(word));
                }
            }
            BigDecimal sum = BigDecimal.ZERO;
            for (BigDecimal i : data) {
                sum = sum.add(i);
            }
            double       sumDouble  = sum.doubleValue() / data.size();
            NumberFormat formatter  = new DecimalFormat("#0.000000");
            String       nameString = String.join(" ", name);
            System.out.println(formatter.format(sumDouble) + " " + nameString);
        }
    }
}
