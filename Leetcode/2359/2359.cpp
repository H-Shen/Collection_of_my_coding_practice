constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 1e5+5;

vector<vector<int>> adj;
int dist1[MAXN];
int dist2[MAXN];
int n;

void dijkstra1(int node) {
    memset(dist1, 0x3f, sizeof dist1);
    dist1[node] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    int u = node;
    int du;
    pq.push({dist1[u], u});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        u = p.second;
        du = p.first;
        if (du != dist1[u]) continue;
        for (const auto &v : adj[u]) {
            if (dist1[u] + 1 < dist1[v]) {
                dist1[v] = dist1[u] + 1;
                pq.push({dist1[v], v});
            }
        }
    }
}

void dijkstra2(int node) {
    memset(dist2, 0x3f, sizeof dist2);
    dist2[node] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    int u = node;
    int du;
    pq.push({dist2[u], u});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        u = p.second;
        du = p.first;
        if (du != dist2[u]) continue;
        for (const auto &v : adj[u]) {
            if (dist2[u] + 1 < dist2[v]) {
                dist2[v] = dist2[u] + 1;
                pq.push({dist2[v], v});
            }
        }
    }
}


class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>>().swap(adj);
        n = (int)edges.size();
        adj.resize(n);
        int u,v;
        for (int i = 0; i < n; ++i) {
            u = i;
            v = edges[i];
            if (v != -1) {
                adj[u].emplace_back(v);
            }
        }
        dijkstra1(node1);
        dijkstra2(node2);
        int ans = INF;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INF && dist2[i] != INF) {
                ans = min(ans, max(dist1[i], dist2[i]));
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INF && dist2[i] != INF) {
                if (max(dist1[i], dist2[i]) == ans) {
                    return i;
                }
            }
        }
        return -1;
    }
};