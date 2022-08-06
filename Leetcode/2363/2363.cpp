class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int> unmap;
        for (auto&i : items1) {
            unmap[i[0]] += i[1];
        }
        for (auto&i : items2) {
            unmap[i[0]] += i[1];
        }
        vector<vector<int>> ans(unmap.size());
        int i = 0;
        for (auto& [k,v] : unmap) {
            ans[i].emplace_back(k);
            ans[i].emplace_back(v);
            ++i;
        }
        sort(ans.begin(),ans.end(),[&](const auto &l, const auto &r){
            return l[0] < r[0];
        });
        return ans;
    }
};