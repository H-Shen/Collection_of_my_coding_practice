constexpr int MAXN = 105;

class Solution {
public:
    int dp[MAXN][MAXN];
    int solve(int i, int j, const string &s) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i > j) {
            dp[i][j] = 0;
            return dp[i][j];
        }
        dp[i][j] = 1+solve(i+1,j,s);
        for (int k = i+1; k < j+1; ++k) {
            if (s[i] == s[k]) {
                dp[i][j] = min(dp[i][j], solve(i,k-1,s)+solve(k+1,j,s));
            }
        } 
        return dp[i][j];
    }
    int strangePrinter(string s) {
        memset(dp, -1, sizeof dp);
        int n = (int)s.size();
        return solve(0, n-1,s);
    }
};