constexpr int MAXN = 1e3+5;
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    bitset<MAXN> bs[MAXN];
    int validSubarraySplit(vector<int>& nums) {
        int n = (int)nums.size();
        for (auto&i : bs) {
            i.reset();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (gcd(nums[i],nums[j]) > 1) {
                    bs[i][j] = true;
                    bs[j][i] = true;
                }
            }
        }
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (bs[i-1][j]) {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};