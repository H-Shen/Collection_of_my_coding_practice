class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxVal = -1;
        int n = (int)nums.size();
        for (int i = 0; i < n / 2; ++i) {
            maxVal = max(maxVal, nums[i] + nums[n-i-1]);
        }
        return maxVal;
    }
};