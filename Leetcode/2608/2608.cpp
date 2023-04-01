constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 1005;

vector<unordered_set<int>> adj;
int dist[MAXN];
int nodes;
int ans;
int dijkstra(int src, int dest) {
    memset(dist, 0x3f, sizeof dist);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({dist[src], src});
    int u;
    int d_u;
    pair<int,int> p;
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        d_u = p.first;
        u = p.second;
        if (d_u != dist[u]) {
            continue;
        }
        for (const auto& v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dest];
}

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // Dijkstra
        // O(m(n+m)logn)
        vector<unordered_set<int>>().swap(adj);
        nodes = n;
        adj.resize(nodes);
        int u,v;
        for (const auto&i : edges) {
            u = i[0];
            v = i[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        ans = -1;
        // enumerate each edge
        int d;
        for (const auto&i : edges) {
            u = i[0];
            v = i[1];
            adj[u].erase(v);
            adj[v].erase(u);
            d = dijkstra(u, v);
            if (d != INF) {
                if (ans == -1) {
                    ans = d + 1;
                }
                else {
                    ans = min(ans, d + 1);
                }
            }
            adj[u].insert(v);
            adj[v].insert(u);
        }
        return ans;
    }
};