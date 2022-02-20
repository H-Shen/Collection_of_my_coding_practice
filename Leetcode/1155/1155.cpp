using ll = long long;
constexpr ll MOD = 1e9+7;
constexpr int MAXN = 35;
constexpr int N = 1005;

ll dp[MAXN][N];

// dp[1][j] = 0 (j > k)
// dp[1][j] = 1 (j <= k)
// dp[n][target] = dp[n-1][target-1] + dp[n-1][target-2] + ... + dp[n-1][j]
ll solve(int n, int k, int target) {
    if (dp[n][target] != -1) return dp[n][target];
    dp[n][target] = 0;
    if (target <= k) {
        for (int i = 1; target-i >= 1; ++i) {
            dp[n][target] = (dp[n][target] + solve(n-1,k,target-i)) % MOD;
        }
    }
    else {
        for (int i = 1; i <= k; ++i) {
            dp[n][target] = (dp[n][target] + solve(n-1,k,target-i)) % MOD;
        }
    }
    return dp[n][target];
}

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = -1;
                }
            }
        }
        for (int i = 1; i < MAXN; ++i) {
            if (i <= k) {
                dp[1][i] = 1;
            }
            else {
                dp[1][i] = 0;
            }
        }
        return (int)(solve(n, k, target) % MOD);
    }
};