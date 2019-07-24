import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) throws NoSuchAlgorithmException {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner       in   = new Scanner(System.in);
        String        s    = in.nextLine();
        MessageDigest md   = MessageDigest.getInstance("SHA-256");
        byte[]        temp = md.digest(s.getBytes(StandardCharsets.UTF_8));

        // output
        StringBuilder sb = new StringBuilder();
        for (byte b : temp) {
            sb.append(String.format("%02x", b));
        }
        System.out.println(sb.toString());
    }
}

