constexpr int MAXN = 1005;
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> pre;
    bool foundPath;
    bitset<MAXN> vis;
    int dist[MAXN];
    void dfs(int u, int dest) {
        if (foundPath) {
            return;
        }
        if (u == dest) {
            foundPath = true;
            return;
        }
        vis[u] = true;
        for (auto& v : adj[u]) {
            if (!vis[v]) {
                pre[v] = u;
                dfs(v, dest);
            }
        }
    }
    vector<int> getPath(int src, int dest) {
        decltype(pre)().swap(pre);
        pre.resize(n, -1);
        foundPath = false;
        vis.reset();
        dfs(src, dest);
        vector<int> path;
        for (int i = dest; ; i = pre[i]) {
            path.emplace_back(i);
            if (i == src) break;
        }
        return path;
    }
    void bfs(int src) {
        memset(dist, 0x3f, sizeof dist);
        vis.reset();
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        int u;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (auto& v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        this->n = n;
        decltype(adj)().swap(adj);
        adj.resize(n);
        for (auto&i : edges) {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        int m = (int)query.size();
        vector<int> result(m);
        int src, dest, node;
        int minDist;
        for (int i = 0; i < m; ++i) {
            src = query[i][0];
            dest = query[i][1];
            node = query[i][2];
            minDist = INF;
            auto path = getPath(src, dest);
            bfs(node);
            for (auto& j : path) {
                minDist = min(minDist, dist[j]);
            }
            for (auto& j : path) {
                if (dist[j] == minDist) {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};