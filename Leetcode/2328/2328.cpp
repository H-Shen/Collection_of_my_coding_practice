constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 1005;
constexpr int STEPS = 4;
constexpr int MOD = 1e9+7;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int dp[MAXN][MAXN];
int n, m;


int solve(int i, int j, vector<vector<int>>& grid) {
    if (dp[i][j] != INF) {
        return dp[i][j];
    }
    dp[i][j] = 1;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
            if (grid[new_i][new_j] > grid[i][j]) {
                dp[i][j] = (dp[i][j] + solve(new_i, new_j, grid)) % MOD;
            }
        }
    }
    return dp[i][j] % MOD;
}

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        memset(dp, 0x3f, sizeof dp);
        n = (int)grid.size();
        m = (int)grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = (ans + solve(i, j, grid)) % MOD;
            }
        }
        return ans;
    }
};