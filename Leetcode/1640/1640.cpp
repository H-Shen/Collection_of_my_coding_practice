class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> unmap;
        int n = (int)arr.size();
        int m = (int)pieces.size();
        for (int i = 0; i < m; ++i) {
            for (const auto &j : pieces[i]) {
                unmap[j] = i;
            }
        }
        int index = 0;
        while (index < n) {
            if (unmap.find(arr[index]) == unmap.end()) {
                return false;
            }
            auto &v = pieces[unmap[arr[index]]];
            int endIndex = index + (int)v.size();
            if (endIndex > n) {
                return false;
            }
            for (int i = index, j = 0; j < (int)v.size(); ++i, ++j) {
                if (arr[i] != v[j]) {
                    return false;
                }
            }
            index = endIndex;
        }
        return true;
    }
};