using ll = long long;

class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int n = (int)nums.size();
        ll sum = 0;
        for (auto&i : nums) sum += i;
        ll maxSum = numeric_limits<ll>::min();
        ll preSum = 0;
        for (int i = 0; i < n; ++i) {
            preSum += nums[i];
            maxSum = max(maxSum, max(preSum, sum - preSum + (ll)nums[i]));
        }
        return maxSum;
    }
};