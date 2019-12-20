// https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        int s = 0;
        if (n <= 0 || m <= 0) {
            return -1;
        }
        for (int i = 2; i <= n; i++) {
            s = (s + m) % i;
        }
        return s;
    }
};