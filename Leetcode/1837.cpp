class Solution {
public:
    int sumBase(int n, int k) {
        string s;
        while (n > 0) {
            s += to_string(n % k);
            n /= k;
        }
        int sum = 0;
        for (const auto &i : s) {
            sum += (int)(i - '0');
        }
        return sum;
    }
};