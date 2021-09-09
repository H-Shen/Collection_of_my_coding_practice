class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = (int)nums.size();
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        constexpr int MAXN = 6*1e4+5;
        vector<int> stats[MAXN]{};
        for (int i = 0; i < n+1; ++i) {
            stats[pre[i] + goal].emplace_back(i);
        }
        int counter = 0;
        for (int r = 0; r < n+1; ++r) {
            if (!stats[pre[r]].empty()) {
                if (r <= stats[pre[r]][0]) {
                    continue;
                }
                auto iter = --lower_bound(stats[pre[r]].begin(),stats[pre[r]].end(),r);
                counter += (int)(iter - stats[pre[r]].begin()) + 1;
            }
        }
        return counter;
    }
};