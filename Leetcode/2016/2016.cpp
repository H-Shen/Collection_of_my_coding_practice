class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = -1;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (nums[i] < nums[j]) {
                    ans = max(ans, nums[j]-nums[i]);
                }
            }
        }
        return ans;
    }
};