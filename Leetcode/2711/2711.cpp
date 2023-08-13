class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                unordered_set<int> topLeft;
                new_i = i;
                new_j = j;
                --new_i;
                --new_j;
                while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    topLeft.insert(grid[new_i][new_j]);
                    --new_i;
                    --new_j;
                }
                unordered_set<int> bottomRight;
                new_i = i;
                new_j = j;
                ++new_i;
                ++new_j;
                while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    bottomRight.insert(grid[new_i][new_j]);
                    ++new_i;
                    ++new_j;
                }
                ans[i][j] = abs((int)topLeft.size() - (int)bottomRight.size());
            }
        }
        return ans;
    }
};