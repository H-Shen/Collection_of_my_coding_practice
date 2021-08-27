class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

        if (triangle.empty()) {
            return 0;
        }

        int n = static_cast<int>(triangle.size());
        vector < vector <int> > dp(n);
        int i, j;

        for (i = 0; i < n; ++i) {
            dp[i].resize(i + 1);
        }

        dp[0][0] = triangle[0][0];

        //dp[i][0]
        for (i = 1; i < n; ++i) {
            dp[i][0] = triangle[i][0] + dp[i - 1][0];
        }

        //dp[i][j]
        for (i = 1; i < n; ++i) {
            for (j = 1; j <= i; ++j) {
                if (i == j) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }

        int res = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return res;
    }
};