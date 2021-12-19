using ll = long long;
constexpr int MAXN = 1e5+5;
ll dp[MAXN];

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = (int)prices.size();
        fill(dp, dp+n, 1);
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i-1] - 1) {
                dp[i] = max(dp[i], dp[i-1]+1);
            }
        }
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += dp[i];
        }
        return sum;
    }
};