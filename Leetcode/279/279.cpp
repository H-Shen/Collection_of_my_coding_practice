constexpr int MAXN = 1e4+5;
constexpr int N = 100;
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    bitset<MAXN> isPs;
    vector<int> ps;
    vector<int> dp;
    
    int dfs(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = INF;
        if (n == 0) {
            return dp[n];
        }
        if (isPs[n]) {
            dp[n] = 1;
            return dp[n];
        }
        for (const auto &i : ps) {
            if (n - i >= 0) {
                dp[n] = min(dp[n], 1 + dfs(n - i));
            }
        }
        return dp[n];
    }
    int numSquares(int n) {
        isPs.reset();
        vector<int>().swap(ps);
        vector<int>().swap(dp);
        // pre
        for (int i = 1; i <= N; ++i) {
            isPs[i*i] = true;
            ps.emplace_back(i*i);
        }
        dp.resize(n+1, -1);
        return dfs(n);
    }
};