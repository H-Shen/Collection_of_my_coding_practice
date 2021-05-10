class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int> > unmap;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            int m = (int)nums[i].size();
            for (int j = 0; j < m; ++j) {
                unmap[i+j].emplace_back(nums[i][j]);
            }
        }
        vector<int> result, vec;
        for (auto &[k, vList] : unmap) {
            reverse(vList.begin(), vList.end());
            vec.emplace_back(k);
        }
        sort(vec.begin(), vec.end());
        for (const auto &i : vec) {
            for (const auto &j : unmap[i]) {
                result.emplace_back(j);
            } 
        }
        return result;
    }
};