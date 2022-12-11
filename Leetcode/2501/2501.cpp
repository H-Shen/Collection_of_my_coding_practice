class Solution {
public:
    unordered_map<int,int> memo;
    inline
    int dp(int n, unordered_set<int>& unset) {
        if (memo.count(n) > 0) {
            return memo[n];
        }
        memo[n] = 1;
        int temp = (int)sqrt(n*1.0);
        if (temp*temp==n && unset.count(temp)>0) {
            memo[n] = 1 + dp(temp, unset);
        }
        return memo[n];
    }
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> unset(nums.begin(),nums.end());
        memo.clear();
        int ans = -1;
        int temp;
        for (auto&i : unset) {
            temp = dp(i, unset);
            if (temp > 1) {
                ans = max(temp, ans);
            }
        }
        return ans;
    }
};