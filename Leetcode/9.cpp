class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }

        int x_copy(x);
        const int MAXN = 15;
        int A[MAXN];
        int length = 0;
        while (x_copy > 0) {
            A[length++] = x_copy % 10;
            x_copy /= 10;
        }
        for (int i = 0; i <= (length - 1) / 2; ++i) {
            if (A[i] != A[length - i - 1]) {
                return false;
            }
        }
        return true;
    }
};