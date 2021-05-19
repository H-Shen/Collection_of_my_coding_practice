class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = numeric_limits<int>::max();
        int n = (int)matrix.size();
        vector<vector<int> > dp(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                }
                else if (j == n - 1) {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                else {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[n-1][j]);
        }
        return minSum;
    }
};