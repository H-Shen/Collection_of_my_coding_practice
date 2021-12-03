constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 1005;
constexpr int MAX_DISCOUNTS = 505;

int w[MAXN][MAXN];
int dist[MAXN][MAX_DISCOUNTS];
vector<vector<int>> adj;

auto cmp = [](const pair<int,pair<int,int>> &l, const pair<int,pair<int,int>> &r) {
    return l.first > r.first;
};


// Node(u, discounts) --> Node(v, discounts) w: w[u][v]
// Node(u, discounts) --> Node(v, discounts-1) w : w[u][v]/2 (discounts > 0)

void dijkstra(int discounts, int n) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(cmp) > pq(cmp);
    for (int i = 0; i <= discounts; ++i) {
        dist[0][i] = 0;
    }
    pq.push({0,{0,discounts}});
    int d_u, u, remaining_discounts, half_w;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        d_u = p.first;
        u = p.second.first;
        remaining_discounts = p.second.second;
        if (d_u != dist[u][remaining_discounts]) {
            continue;
        }
        for (const auto &v : adj[u]) {
            if (dist[v][remaining_discounts] > dist[u][remaining_discounts] + w[u][v]) {
                dist[v][remaining_discounts] = dist[u][remaining_discounts] + w[u][v];
                pq.push({dist[v][remaining_discounts], {v,remaining_discounts}});
            }
            half_w = w[u][v] >> 1;
            if (remaining_discounts > 0 && dist[v][remaining_discounts-1] > dist[u][remaining_discounts] + half_w) {
                dist[v][remaining_discounts-1] = dist[u][remaining_discounts] + half_w;
                pq.push({dist[v][remaining_discounts-1], {v,remaining_discounts-1}});
            }
        }
    }
}

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        memset(w, 0, sizeof w);
        decltype(adj)().swap(adj);
        adj.resize(n);
        int u, v;
        for (auto&i : highways) {
            u = i[0];
            v = i[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            w[u][v] = w[v][u] = i[2];
        }
        dijkstra(discounts, n);
        int temp = INF;
        for (int i = 0; i <= discounts; ++i) {
            temp = min(temp, dist[n-1][i]);
        }
        return (temp == INF) ? -1 : temp; 
    }
};