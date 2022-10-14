class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;
        int val;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                val = nums[i];
                continue;
            }
            val = gcd(nums[i], val);
            if (val == 1) {
                ++ans;
                val = nums[i];
            }
        }
        ++ans;
        return ans;
    }
};