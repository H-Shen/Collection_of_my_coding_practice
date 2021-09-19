class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = grid[0][i];
        }
        vector<vector<int>> minFromLeft(n, vector<int>(n));
        minFromLeft[0][0] = dp[0][0];
        for (int i = 1; i < n; ++i) {
            minFromLeft[0][i] = min(dp[0][i], minFromLeft[0][i-1]);
        }
        vector<vector<int>> minFromRight(n, vector<int>(n));
        minFromRight[0][n-1] = dp[0][n-1];
        for (int i = n-2; i >= 0; --i) {
            minFromRight[0][i] = min(dp[0][i], minFromRight[0][i+1]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = minFromRight[i-1][j+1] + grid[i][j];
                }
                else if (j == n-1) {
                    dp[i][j] = minFromLeft[i-1][j-1] + grid[i][j];
                }
                else {
                    dp[i][j] = min(minFromLeft[i-1][j-1], minFromRight[i-1][j+1]) + grid[i][j];
                }
            }
            // update
            minFromLeft[i][0] = dp[i][0];
            for (int j = 1; j < n; ++j) {
                minFromLeft[i][j] = min(minFromLeft[i][j-1], dp[i][j]);
            }
            minFromRight[i][n-1] = dp[i][n-1];
            for (int j = n-2; j >= 0; --j) {
                minFromRight[i][j] = min(minFromRight[i][j+1], dp[i][j]);
            }
        }
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};