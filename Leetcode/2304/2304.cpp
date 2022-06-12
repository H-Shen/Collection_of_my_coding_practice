class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, numeric_limits<int>::max()));
        for (int i = 0; i < m; ++i) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i-1][k] + moveCost[grid[i-1][k]][j]);
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};