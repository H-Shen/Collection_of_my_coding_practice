class Solution {
public:
    inline
    bool check(vector<int>& dp, int l, int r) {
        return dp[r] >= r-l+1;
    }
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = (int)security.size();
        vector<int> dp1(n); // increasing
        dp1[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (security[i-1] <= security[i]) {
                dp1[i] = dp1[i-1] + 1;
            }
            else {
                dp1[i] = 1;
            }
        }
        vector<int> dp2(n); // decreasing
        dp2[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (security[i-1] >= security[i]) {
                dp2[i] = dp2[i-1] + 1;
            }
            else {
                dp2[i] = 1;
            }
        }
        vector<int> ans;
        for (int i = time; i + time < n; ++i) {
            if (check(dp2, i-time, i) && check(dp1, i, i+time)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};