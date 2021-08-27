class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        int counter = 0;
        // Case 1:
        for (int i = 1; i <= n; ++i) {
            if (pre[i] == k) {
                ++counter;
            }
        }
        // Case 2:
        unordered_map<int, vector<int> > unmap;
        for (int i = 1; i <= n; ++i) {
            unmap[pre[i]].emplace_back(i);
        }
        for (int l = 1; l <= n; ++l) {
            if (unmap.find(pre[l]+k) != unmap.end()) {
                auto &v = unmap[pre[l]+k];
                auto iter = upper_bound(v.begin(),v.end(),l);
                if (iter != v.end()) {
                    counter += (int)(v.end() - iter);
                }
            }
        }
        return counter;
    }
};