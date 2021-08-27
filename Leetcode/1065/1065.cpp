class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        unordered_map<string, vector<vector<int> > > unmap;
        int n = (int)text.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unmap[text.substr(i, j - i + 1)].emplace_back(vector<int>{i,j});
            }
        }
        vector<vector<int>> result;
        for (const auto &i : words) {
            if (unmap.find(i) != unmap.end()) {
                for (const auto &j : unmap[i]) {
                    result.emplace_back(j);
                } 
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};