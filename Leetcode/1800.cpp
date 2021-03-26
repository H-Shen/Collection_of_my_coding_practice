class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.front();
        int n = (int)nums.size();
        int maxSum = -1;
        int currentSum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            }
            else {
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }
        maxSum = max(maxSum, currentSum);
        return maxSum;
    }
};