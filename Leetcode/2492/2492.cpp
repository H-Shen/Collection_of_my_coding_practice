constexpr int MAXN = 1e5+5;

class Solution {
public:
    vector<vector<int>> adj;
    bitset<MAXN> vis;
    void dfs(int u, int target) {
        vis[u] = true;
        if (u == target) {
            return;
        }
        for (auto &v : adj[u]) {
            if (!vis[v]) {
                dfs(v, target);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        decltype(adj)().swap(adj);
        adj.resize(n+1);
        vis.reset();
        int minVal = numeric_limits<int>::max();
        int u,v,w;
        for (auto&i : roads) {
            u = i[0];
            v = i[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1, n);
        for (auto&i : roads) {
            u = i[0];
            v = i[1];
            w = i[2];
            if (vis[u] && vis[v]) {
                minVal = min(minVal, w);
            }
        }
        return minVal;
    }
};