// https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af

class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        int i, j;
        int c = 0;
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n + 1; ++j) {
                string k(A, i, j - i);
                string k2(k);
                reverse(k.begin(), k.end());
                if (k2 == k && j - i > c) {
                    c = j - i;
                }
            }
        }
        return c;
    }
};