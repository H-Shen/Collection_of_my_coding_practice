namespace BipartiteCheck {
    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAXN = 2005;
    bool bfs(const vector<vector<int> > &adj, int n) {
        queue<int> q;
        int color[MAXN];
        memset(color, 0x3f, sizeof color);
        for (int s = 1; s <= n; ++s) {
            if (color[s] == INF) {
                color[s] = 0;
                q.push(s);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const auto &v : adj[u]) {
                    if (color[v] == INF) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int> > adj(BipartiteCheck::MAXN);
        for (const auto &i : dislikes) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        return BipartiteCheck::bfs(adj, N);
    }
};