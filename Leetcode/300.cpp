class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int pos, const vector<int> &A) {
        if (dp[pos] != -1) {
            return dp[pos];
        }
        dp[pos] = 1;
        for (int i = pos; i < n; ++i) {
            if (A.at(pos) < A.at(i)) {
                dp[pos] = max(dp[pos], solve(i, A)+1);
            }
        }
        return dp[pos];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>().swap(dp);
        n = (int)nums.size();
        dp.resize(n,-1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};