constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 1e5+5;

vector<vector<int>> adj;
int n;
int dist[MAXN];

void bfs() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (const auto& v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}


class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        n = (int)patience.size();
        vector<vector<int>>().swap(adj);
        adj.resize(n);
        int u,v;
        for (auto&i : edges) {
            u = i[0];
            v = i[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        bfs();
        int result = -1;
        int cost;
        for (int i = 1; i < n; ++i) {
            cost = dist[i] * 2;
            if (cost <= patience[i]) {
                result = max(result, cost);
            }
            else {
                if (cost % patience[i] == 0) {
                    result = max(result, (cost / patience[i] - 1) * patience[i] + cost);
                }
                else {
                    result = max(result, (cost / patience[i]) * patience[i] + cost);
                }
            }
        }
        return result+1;
    }
};