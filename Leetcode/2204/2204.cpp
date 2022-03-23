constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 1e5+5;

namespace Toposort {
    vector<vector<int>> adj;
    vector<int> deg;
    bitset<MAXN> vis;
    int n;
    void Kahn() {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] <= 1) {
                q.push(i);
            }
        }
        int u;
        while (!q.empty()) {
            u = q.front();
            vis[u] = true;
            q.pop();
            for (auto& v : adj[u]) {
                --deg[v];
                if (deg[v] == 1) {
                    q.push(v);
                }
            }
        }
    }
}

vector<vector<int>> contract() {
    vector<vector<int>> adj(Toposort::n+5);
    int u,v;
    for (int i = 0; i < Toposort::n; ++i) {
        if (Toposort::vis[i]) {
            u = i;
        }
        else {
            u = Toposort::n;
        }
        for (auto& j : Toposort::adj[i]) {
            if (Toposort::vis[j]) {
                v = j;
            }
            else {
                v = Toposort::n;
            }
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    return adj;
}

vector<int> bfs(vector<vector<int>>& adj) {
    int dist[MAXN];
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(Toposort::n);
    dist[Toposort::n] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : adj[u]) {
            if (dist[v] == INF) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    vector<int> result(Toposort::n);
    for (int i = 0; i < Toposort::n; ++i) {
        if (Toposort::vis[i]) {
            result[i] = dist[i];
        }
        else {
            result[i] = 0;
        }
    }
    return result;
}

class Solution {
public:
    // Toposort + Contract the cycle + Bfs: O(n)
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        Toposort::n = n;
        vector<vector<int>>().swap(Toposort::adj);
        Toposort::adj.resize(n);
        vector<int>().swap(Toposort::deg);
        Toposort::deg.resize(n);
        Toposort::vis.reset();
        for (auto&i : edges) {
            Toposort::adj[i[0]].emplace_back(i[1]);
            Toposort::adj[i[1]].emplace_back(i[0]);
            ++Toposort::deg[i[0]];
            ++Toposort::deg[i[1]];
        }
        Toposort::Kahn();
        vector<vector<int>> newAdj = contract();
        return bfs(newAdj);
    }
};