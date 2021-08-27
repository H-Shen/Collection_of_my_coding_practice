class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        unordered_map<int,int> unmap;
        for (int i = 0; i < n+1; ++i) {
            auto iter = unmap.find(pre[i]+k);
            if (iter == unmap.end()) {
                unmap[pre[i]+k] = i;
            } else {
                iter->second = min(iter->second, i);
            }
        }
        int maxSize = 0;
        for (int r = 1; r <= n; ++r) {
            auto iter = unmap.find(pre[r]);
            if (iter != unmap.end()) {
                auto &a = iter->second;
                if (r <= a) {
                    continue;
                }
                maxSize = max(r - a, maxSize);
            }
        }
        return maxSize;
    }
};