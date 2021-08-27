class Solution {
public:
    // $n^2 = \sum_{i=1}^{n} (2i - 1)$
    bool isPerfectSquare(int num) {
        using ll = long long;
        ll upper = 1 << 16;
        ll sum = 0;
        for (ll i = 1; i <= upper; ++i) {
            sum += ((i << 1) - 1);
            if (sum == num) return true;
        }
        return false;
    }
};