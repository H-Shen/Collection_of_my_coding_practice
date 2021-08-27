using ll = long long;

// dp[i][j] = points[i][j] + max(dp[i-1][j']-abs(j-j'))

// dp[i][j] = points[i][j] + max(dp[i-1][j']-j+j') (j >= j')
// dp[i][j] = points[i][j] + max(dp[i-1][j']+j-j') (j < j')

// dp[i][j] = points[i][j]-j + max(dp[i-1][j']+j') (j >= j')
// dp[i][j] = points[i][j]+j + max(dp[i-1][j']-j') (j < j')

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        int m = (int)points[0].size();
        vector<vector<ll> > dp(n, vector<ll>(m));
        for (int j = 0; j < m; ++j) {
            dp[0][j] = points[0][j];
        }
        // maxLeft = max(dp[i-1][j] + j) (0 <= j < m)
        // maxRight = max(dp[i-1][j] - j) (0 <= j < m)
        ll maxLeft, maxRight;
        for (int i = 1; i < n; ++i) {
            // reset
            maxLeft = numeric_limits<ll>::min();
            maxRight = numeric_limits<ll>::min();
            for (int j = 0; j < m; ++j) {
                maxLeft = max(maxLeft, dp[i-1][j] + j);
                dp[i][j] = max(dp[i][j], points[i][j] - j + maxLeft); 
            }
            // Why scan from right to left? Because of the requirement of j < j' in the formula
            for (int j = m - 1; j >= 0; --j) {
                maxRight = max(maxRight, dp[i-1][j] - j);
                dp[i][j] = max(dp[i][j], points[i][j] + j + maxRight);
            }
        }
        ll maxVal = 0;
        for (int j = 0; j < m; ++j) {
            maxVal = max(maxVal, dp[n-1][j]);
        }
        return maxVal;
    }
};