import java.util.*;
public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Deque<Integer> deque = new ArrayDeque<>();
        HashMap<Integer, Integer> freq = new HashMap<>();
        int n = in.nextInt();
        int m = in.nextInt();
        int maxUniqueIntegers = -1;
        for (int i = 0; i < n; i++) {
            int num = in.nextInt();
            if (deque.size() < m) {
                if (freq.containsKey(num)) {
                    // num is in the hash map
                    freq.put(num, freq.get(num) + 1);
                } else {
                    // num is not in the hash map
                    freq.put(num, 1);
                }
                deque.addLast(num);
                if (deque.size() == m) {
                    maxUniqueIntegers = Math.max(maxUniqueIntegers, freq.size());
                }
            } else {
                Integer temp = deque.pollFirst();
                freq.put(temp, freq.get(temp) - 1);
                // if freq.get(temp) == 0, then remove it
                if (freq.get(temp) == 0) {
                    freq.remove(temp);
                }

                if (freq.containsKey(num)) {
                    // num is in the hash map
                    freq.put(num, freq.get(num) + 1);
                } else {
                    // num is not in the hash map
                    freq.put(num, 1);
                }
                deque.addLast(num);
                maxUniqueIntegers = Math.max(maxUniqueIntegers, freq.size());
            }
        }
        System.out.println(maxUniqueIntegers);
    }
}