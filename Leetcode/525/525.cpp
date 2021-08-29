class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // pre[r] - pre[l-1] = (r-(l-1))/2
        // 2pre[r] - 2pre[l-1] = r-(l-1)
        // 2pre[r] - r = 2pre[l-1] - (l-1)
        int n = (int)nums.size();
        vector<int> pre(n+1);
        for (int i = 1; i < n+1; ++i) {
            pre[i] = pre[i-1]+nums[i-1];
        }
        unordered_map<int,vector<int>>unmap;
        for (int i = 0; i < n+1; ++i) {
            unmap[(pre[i]<<1)-i].emplace_back(i);
        }
        int ans = 0;
        for (const auto &[k,v] : unmap) {
            if (v.size() > 1) {
                ans = max(ans, v.back()-v.front());
            }
        }
        return ans;
    }
};