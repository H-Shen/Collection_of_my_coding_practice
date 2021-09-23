constexpr int MAXN = 505;
constexpr int INF = 0x3f3f3f3f;

vector<vector<int>> AL;
bitset<MAXN> vis;

void dfs(int u) {
    for (const auto &v : AL[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = (int)quiet.size();
        decltype(AL)().swap(AL);
        AL.resize(n);
        int u, v;
        for (const auto &i : richer) {
            u = i[1];
            v = i[0];
            AL[u].emplace_back(v);
        }
        vector<int> ans(n);
        int minQuiet;
        for (int i = 0; i < n; ++i) {
            vis.reset();
            vis[i] = true;
            dfs(i);
            minQuiet = INF;
            for (int j = 0; j < n; ++j) {
                if (vis[j] && minQuiet > quiet[j]) {
                    minQuiet = quiet[j];
                    ans[i] = j;
                }
            }
        }
        return ans;
    }
};