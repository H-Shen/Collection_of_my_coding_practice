constexpr double EPS = 1e-7;
constexpr double INF = 1e20;

class Solution {
public:
    vector<vector<double> > dp;
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = (int)dist.size();
        decltype(dp)().swap(dp);
        dp.resize(n+1, vector<double>(n+1, INF));
        dp[0][0] = 0.0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j != i) {
                    dp[i][j] = min(dp[i][j], ceil(dp[i-1][j] + dist[i-1] * 1.0 / speed - EPS));
                }
                if (j != 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + dist[i-1] * 1.0 / speed);
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (dp[n][i] < hoursBefore + EPS) {
                return i;
            }
        }
        return -1;
    }
};