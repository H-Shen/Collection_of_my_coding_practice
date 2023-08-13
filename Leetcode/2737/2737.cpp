constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 505;

vector<vector<pair<int,int>>> adj;
int dist[MAXN];

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
    pq.push({dist[s], s});
    pair<int,int> p;
    int u, d_u;
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        u = p.second;
        d_u = p.first;
        if (d_u != dist[u]) continue;
        for (const auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        decltype(adj)().swap(adj);
        adj.resize(n);
        for (auto&i : edges) {
            adj[i[0]].emplace_back(i[1],i[2]);
        }
        dijkstra(s);
        int minDist = INF;
        for (auto&i : marked) {
            minDist = min(minDist, dist[i]);
        }
        return minDist == INF ? -1 : minDist;
    }
};