class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        auto encrypt = [](int x) {
            if (x == 0) {
                return x;
            }
            int cnt = 0;
            int maxDigit = -1;
            while (x > 0) {
                ++cnt;
                maxDigit = max(maxDigit, x % 10);
                x /= 10;
            }
            // (10^cnt-1) / 9 * maxDigit
            int res = 1;
            while (cnt > 0) {
                res *= 10;
                --cnt;
            }
            res--;
            return res / 9 * maxDigit;
        };
        int s = 0;
        for (const auto &i : nums) {
            s += encrypt(i);
        }
        return s;
    }
};