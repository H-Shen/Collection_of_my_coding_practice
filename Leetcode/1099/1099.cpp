class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int i = 0, j = n - 1;
        int maxSum = -1;
        int sum;
        while (i < j) {
            sum = nums[i] + nums[j];
            if (sum >= k) {
                --j;
            } else {
                maxSum = max(maxSum, sum);
                ++i;
            }
        }
        return maxSum;
    }
};