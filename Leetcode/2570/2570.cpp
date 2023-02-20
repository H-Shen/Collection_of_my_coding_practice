class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> unmap;
        for (auto&i : nums1) {
            unmap[i[0]] += i[1];
        }
        for (auto&i : nums2) {
            unmap[i[0]] += i[1];
        }
        vector<vector<int>> result;
        for (auto&[k,v] : unmap) {
            result.emplace_back(vector<int>{k,v});
        }
        sort(result.begin(),result.end(),[&](const auto &l, const auto &r){
            return l[0] < r[0];
        });
        return result;
    }
};