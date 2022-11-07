using ll = long long;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> unmap;
        ll maxSum = 0;
        ll currentSum = 0;
        int n = (int)nums.size();
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
            ++unmap[nums[i]];
        }
        if ((int)unmap.size() == k) {
            maxSum = max(maxSum, currentSum);
        }
        for (int i = k, j = 0; i < n; ++i, ++j) {
            currentSum = currentSum + nums[i] - nums[j];
            --unmap[nums[j]];
            if (unmap[nums[j]] == 0) {
                unmap.erase(nums[j]);
            }
            ++unmap[nums[i]];
            if ((int)unmap.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};