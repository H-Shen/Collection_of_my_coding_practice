class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<int> rowsOne(n);
        vector<int> colsOne(m);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) ++cnt;
            }
            rowsOne[i] = cnt;
        }
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[j][i] == 1) ++cnt;
            }
            colsOne[i] = cnt;
        }
        vector<vector<int>> diff(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diff[i][j] = rowsOne[i] + colsOne[j] - (n - rowsOne[i]) - (m - colsOne[j]);
            }
        }
        return diff;
    }
};