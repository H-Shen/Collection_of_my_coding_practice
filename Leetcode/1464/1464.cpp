class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxValue = numeric_limits<int>::min();
        int n = (int)nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j < n; ++j) {
                maxValue = max(maxValue, (nums[i]-1)*(nums[j]-1));
            }
        }
        return maxValue;
    }
};