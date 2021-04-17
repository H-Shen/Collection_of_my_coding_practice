class Solution {
public:
    int totalMoney(int n) {
        int a = 1; int b = 7;
        int sum = 0;
        for (int i = 0, j = a; i < n; ++i) {
            sum += j;
            ++j;
            if (j > b) {
                ++a;
                ++b;
                j = a;
            }
        }
        return sum;
    }
};