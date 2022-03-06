constexpr int MAXN = 1e3+5;
bitset<MAXN> vis;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u) {
        for (auto &v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dfs(adj, v);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int u,v;
        // reversed edge
        for (auto&i : edges) {
            v = i[0];
            u = i[1];
            adj[u].emplace_back(v);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            vis.reset();
            dfs(adj, i);
            for (size_t j = vis._Find_first(); j < vis.size(); j = vis._Find_next(j)) {
                ans[i].emplace_back((int)j);
            }
        }
        return ans;
    }
};