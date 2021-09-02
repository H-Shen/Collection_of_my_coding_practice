class Solution {
public:
    bool check(vector<vector<int>>& preRow, vector<vector<int>>& preCol, int i, int j, int k) {
        int l, r;
        l = j+1;
        r = j+k-1+1;
        if (preRow[i][r]-preRow[i][l-1] != k) return false;
        if (preRow[i+k-1][r]-preRow[i+k-1][l-1] != k) return false;
        l = i+1;
        r = i+k-1+1;
        if (preCol[j][r]-preCol[j][l-1] != k) return false;
        if (preCol[j+k-1][r]-preCol[j+k-1][l-1] != k) return false;
        return true;
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<int>> preRow(n, vector<int>(m+1));
        vector<vector<int>> preCol(m, vector<int>(n+1));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                preRow[i][j] = preRow[i][j-1] + grid[i][j-1];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                preCol[i][j] = preCol[i][j-1] + grid[j-1][i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = min(n-i,m-j); k >= 1; --k) {
                    if (k <= ans) {
                        break;
                    }
                    if (check(preRow, preCol, i, j, k)) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans*ans;
    }
};