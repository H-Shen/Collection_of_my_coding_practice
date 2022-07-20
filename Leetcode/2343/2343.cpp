class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int m = (int)queries.size();
        int length = (int)nums[0].size();
        unordered_map<int, vector<int>> unmap;
        for (int i = 0; i < m; ++i) {
            unmap[queries[i][1]].clear();
        }
        vector<int> vec(n);
        iota(vec.begin(),vec.end(),0);
        int outer_k;
        for (auto&[k,v] : unmap) {
            outer_k = k;
            sort(vec.begin(),vec.end(),[&](const int &l, const int &r){
                for (int i = length-outer_k; i < length; ++i) {
                    if (nums[l][i] == nums[r][i]) {
                        continue;
                    }
                    return nums[l][i] < nums[r][i];
                }
                return l < r;
            });
            v = vec;
        }
        vector<int> result(m);
        for (int i = 0; i < m; ++i) {
            result[i] = unmap[queries[i][1]][queries[i][0]-1];
        }
        return result;
    }
};