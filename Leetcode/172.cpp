class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int temp;
        while (n >= 5) {
            temp = n / 5;
            ans += temp;
            n = temp;
        }
        return ans;
    }
};