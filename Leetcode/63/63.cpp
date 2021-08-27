class Solution {
public:
    vector<vector<int> > dp;
    int solve(int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = solve(i-1,j) + solve(i,j-1);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = (int)obstacleGrid.size();
        int m = (int)obstacleGrid.front().size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        } 
        dp.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0] == 1 || dp[i-1][0] == 0) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
        for (int j = 1; j < m; ++j) {
            if (obstacleGrid[0][j] == 1 || dp[0][j-1] == 0) {
                dp[0][j] = 0;
            } else {
                dp[0][j] = 1;
            }
        }
        return solve(n-1,m-1);
    }
};