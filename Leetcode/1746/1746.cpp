constexpr int MAXN = 1e5+5;
int dp1[MAXN];
int dp[MAXN][2];

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = (int)nums.size();
        dp1[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp1[i] = max(dp1[i-1] + nums[i], nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = dp1[i];
        }
        dp[0][1] = nums[0]*nums[0];
        int temp;
        for (int i = 1; i < n; ++i) {
            temp = nums[i]*nums[i];
            dp[i][1] = max(temp,max(dp[i-1][1] + nums[i], dp[i-1][0] + temp));
        }
        int ans = numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};