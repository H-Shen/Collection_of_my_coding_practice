class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = (int)nums.size();
        int minVal = numeric_limits<int>::max();
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (nums[i] < nums[j] && nums[k] < nums[j]) {
                        minVal = min(minVal, nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        return minVal == numeric_limits<int>::max() ? -1 : minVal;
    }
};