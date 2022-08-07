constexpr int MAXN = 1e5+5;

class Solution {
public:
    bitset<MAXN> dp;
    bool validPartition(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) {
            return false;
        }
        else if (n == 2) {
            return nums[0] == nums[1];
        }
        else if (n == 3) {
            return (nums[0] == nums[1] && nums[1] == nums[2]) || (nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2]);
        }
        dp.reset();
        if (nums[0] == nums[1]) {
            dp[1] = true;
        }
        if ((nums[0] == nums[1] && nums[1] == nums[2]) || (nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2])) {
            dp[2] = true;
        }
        for (int i = 3; i < n; ++i) {
            if (dp[i-2] && nums[i] == nums[i-1]) {
                dp[i] = true;
                continue;
            }
            if (dp[i-3] && ((nums[i] == nums[i-1] && nums[i-1] == nums[i-2]) || (nums[i-2] + 1 == nums[i-1] && nums[i-1] + 1 == nums[i]))) {
                dp[i] = true;
                continue;
            }
        }
        return dp[n-1];
    }
};