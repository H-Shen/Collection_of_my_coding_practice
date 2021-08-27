class Solution {
public:
    static constexpr int MAXN = 1695;
    int nthUglyNumber(int n) {
        int dp[MAXN];
        int primeNumbers = 3;
        int count[] = {0, 0, 0};
        int prime[] = {2, 3, 5};
        dp[0] = 1;
        for (int i = 1; i <= n - 1; ++i) {
            dp[i] = numeric_limits<int>::max();
            for (int j = 0; j < primeNumbers; ++j) {
                dp[i] = min(dp[i], dp[count[j]] * prime[j]);
            }
            for (int j = 0; j < primeNumbers; ++j) {
                if (dp[i] == dp[count[j]] * prime[j]) {
                    ++count[j]; // update all counters that satisfy the condition
                }
            }
        }
        return dp[n - 1];
    }
};