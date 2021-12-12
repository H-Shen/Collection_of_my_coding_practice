constexpr int MAXN = 105;

vector<vector<int>> adj;
bitset<MAXN> vis;

void dfs(int u) {
    for (const auto &v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        decltype(adj)().swap(adj);
        int n = (int)bombs.size();
        adj.resize(n);
        double x,y,r,x_j,y_j;
        for (int i = 0; i < n; ++i) {
            x = bombs[i][0];
            y = bombs[i][1];
            r = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    x_j = bombs[j][0];
                    y_j = bombs[j][1];
                    if ((x-x_j)*(x-x_j)+(y-y_j)*(y-y_j) <= r*r) {
                        adj[i].emplace_back(j);
                    }
                }
            }
        }
        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            vis.reset();
            vis[i] = true;
            dfs(i);
            maxVal = max(maxVal, (int)vis.count());
        }
        return maxVal;
    }
};