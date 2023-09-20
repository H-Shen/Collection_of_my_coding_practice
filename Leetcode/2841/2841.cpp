using ll = long long;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> unmap;
        int i;
        ll sum = 0;
        ll maxSum = 0;
        for (i = 0; i < k; ++i) {
            ++unmap[nums[i]];
            sum += (ll)nums[i];
        }
        int n = (int)nums.size();
        if ((int)unmap.size() >= m) {
            maxSum = max(maxSum, sum);
        }
        for (int j = 0; i < n; ++i, ++j) {
            ++unmap[nums[i]];
            --unmap[nums[j]];
            sum += (ll)nums[i];
            sum -= (ll)nums[j];
            if (unmap[nums[j]] == 0) {
                unmap.erase(nums[j]);
            }
            if ((int)unmap.size() >= m) {
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};