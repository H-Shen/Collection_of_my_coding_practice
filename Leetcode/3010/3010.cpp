class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        auto rangeSum = [&](int l, int r) {
            if (l == 0) {
                return pre[r];
            }
            return pre[r] - pre[l-1];
        };
        int answer = numeric_limits<int>::max();
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                answer = min(answer, nums[0] + nums[i] + nums[j]);
            }
        }
        return answer;
    }
};