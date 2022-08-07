constexpr int MAXN = 1e5+5;

class Solution {
public:
    vector<vector<int>> adj;
    bitset<MAXN> vis;
    void dfs(int u, int fa, unordered_set<int>& unset) {
        vis[u] = true;
        for (auto& v : adj[u]) {
            if (v != fa && !vis[v] && unset.count(v) == 0) {
                dfs(v, u, unset);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>().swap(adj);
        adj.resize(n);
        for (auto&i : edges) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        unordered_set<int> unset(restricted.begin(), restricted.end());
        vis.reset();
        dfs(0, -1, unset);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) ++cnt;
        }
        return cnt;
    }
};