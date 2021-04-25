class Solution {
public:
    vector<vector<int> > AL;
    vector<int> dp;
    vector<bool> vis;
    int getLongestPath(int u) {
        if (vis[u]) {
            return dp[u];
        }
        vis[u] = true;
        for (const auto &v : AL[u]) {
            dp[u] = max(dp[u], getLongestPath(v) + 1);
        }
        return dp[u];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = (int)pairs.size();
        AL.resize(n);
        dp.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (pairs[i][1] < pairs[j][0]) {
                    AL[i].emplace_back(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i] = getLongestPath(i);
        }
        return *max_element(dp.begin(), dp.end()) + 1;
    }
};