constexpr int MAXN = 1e4+5;
constexpr int COLORS = 4;
int color[MAXN];
vector<vector<int>> adj;

void dfs(int u) {
    bitset<COLORS> adjColor;
    for (auto&v : adj[u]) {
        if (color[v] != 0) {
            adjColor[color[v] - 1] = true;
        }
    }
    for (int i = 0; i < COLORS; ++i) {
        if (!adjColor[i]) {
            color[u] = i+1;
            break;
        }
    }
    for (auto&v : adj[u]) {
        if (color[v] == 0) {
            dfs(v);
        }
    }
}

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // greedy coloring
        // https://zh.wikipedia.org/wiki/%E5%B8%83%E9%B2%81%E5%85%8B%E5%AE%9A%E7%90%86#cite_note-2
        memset(color, 0, sizeof color);
        decltype(adj)().swap(adj);
        adj.resize(n+1);
        int u,v;
        for (auto& i : paths) {
            u = i[0];
            v = i[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                dfs(i);
            }
        }
        vector<int> result(n);
        for (int i = 1; i <= n; ++i) {
            result[i-1] = color[i];
        }
        return result;
    }
};