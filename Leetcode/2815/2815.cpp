class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = -1;
        auto m = [](int x) {
            if (x < 10) return x;
            int ret = 0;
            while (x > 0) {
                ret = max(ret, x % 10);
                x /= 10;
            }
            return ret;
        };
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (m(nums[i]) == m(nums[j])) ans = max(ans, nums[i]+nums[j]);
            }
        }
        return ans;
    }
};