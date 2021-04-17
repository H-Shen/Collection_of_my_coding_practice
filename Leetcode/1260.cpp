class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = (int)grid.size();
        int m = (int)grid.front().size();
        int total = n * m;
        vector<int> v(total);
        for (int i = 0, c = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v[c++] = grid[i][j];
            }
        }
        rotate(v.rbegin(), v.rbegin() + (k % total) , v.rend());
        for (int i = 0, c = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = v[c++];
            }
        }
        return grid;
    }
};