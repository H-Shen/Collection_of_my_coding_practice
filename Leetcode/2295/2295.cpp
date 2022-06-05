class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, list<int>> unmap;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            unmap[nums[i]].emplace_back(i);
        }
        int u,v;
        for (auto&i : operations) {
            u = i[0];
            v = i[1];
            // make sure it can be done in O(1)
            unmap[v].splice(unmap[v].begin(), unmap[u]);
            unmap.erase(u);
        }
        vector<int> ans(n);
        for (auto&[k, vList] : unmap) {
            for (auto&v : vList) {
                ans[v] = k; 
            }
        }
        return ans;
    }
};