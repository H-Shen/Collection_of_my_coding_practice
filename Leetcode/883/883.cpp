class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, xz = 0, yz = 0;
        int n = (int)grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) ++xy;
            }
        }
        vector<int> maxInCols(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                maxInCols[i] = max(maxInCols[i], grid[j][i]);
            }
        }
        xz = accumulate(maxInCols.begin(), maxInCols.end(), 0);
        vector<int> maxInRows(n);
        for (int i = 0; i < n; ++i) {
            maxInRows[i] = max(maxInRows[i], *max_element(grid[i].begin(),grid[i].end()));
        }
        yz = accumulate(maxInRows.begin(), maxInRows.end(), 0);
        return xy + xz + yz;
    }
};