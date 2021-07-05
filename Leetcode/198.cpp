class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int i, const vector<int> &nums) {
        if (dp[i] != -1) return dp[i];
        for (int j = i+2; j < n; ++j) {
            dp[i] = max(dp[i], nums[i] + solve(j, nums));
        }
        return dp[i];
    }
    int rob(vector<int>& nums) {
        n = (int)nums.size();
        decltype(dp)().swap(dp);
        dp.resize(n, -1);
        dp[n-1] = nums[n-1];
        if (n >= 2) dp[n-2] = nums[n-2];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};