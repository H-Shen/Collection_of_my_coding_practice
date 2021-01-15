namespace Bridges {

    constexpr int INF = 0x3f3f3f3f;
    vector<int> dfs_num;
    vector<int> dfs_low;
    vector<int> dfs_parent;
    int dfsNumberCounter;
    vector<vector<int> > adj;
    vector<vector<int> > bridges;

    void getBridge(int u) {
        dfs_num[u] = dfsNumberCounter;
        ++dfsNumberCounter;
        dfs_low[u] = dfs_num[u];
        for (const auto &v : adj[u]) {
            if (dfs_num[v] == INF) {
                dfs_parent[v] = u;
                getBridge(v);
                if (dfs_low[v] > dfs_num[u]) {
                    bridges.emplace_back(vector<int>{v, u});
                }
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }
            else if (v != dfs_parent[u]) {
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }

    void init(int n) {
        decltype(adj)().swap(adj);
        vector<int>().swap(dfs_num);
        vector<int>().swap(dfs_low);
        vector<int>().swap(dfs_parent);
        decltype(bridges)().swap(bridges);
        dfsNumberCounter = 0;

        dfs_num.resize(n + 5, INF);
        dfs_low.resize(n + 5, 0);
        dfs_parent.resize(n + 5, -1);
        adj.resize(n + 5);
    }
}

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Bridges::init(n);
        int u, v;
        for (const auto &i : connections) {
            u = i[0];
            v = i[1];
            Bridges::adj[u].emplace_back(v);
            Bridges::adj[v].emplace_back(u);
        }
        for (int i = 0; i < n; ++i) {
            if (Bridges::dfs_num[i] == Bridges::INF) {
                Bridges::getBridge(i);
            }
        }
        return Bridges::bridges;
    }
};