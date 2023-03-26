class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        using ll = long long;
        int n = (int)nums.size();
        priority_queue<int, vector<int>, greater<>> pq;
        int ans = 0;
        ll prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum += (ll)nums[i];
            pq.push(nums[i]);
            if (prefixSum < 0) {
                prefixSum -= pq.top();
                pq.pop();
                ++ans;
            }
        }
        return ans;
    }
};