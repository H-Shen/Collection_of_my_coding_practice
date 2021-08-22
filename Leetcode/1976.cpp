using ll = long long;
constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;
constexpr int N = 205;

ll dp[N];
ll dist[N];
vector<vector<pair<int, ll>>> AL;

void dijkstra() {
    for (auto &i : dist) i = INF;
    dist[0] = 0;
    dp[0] = 1;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({dist[0],0});
    pair<ll,int> temp;
    ll d_u;
    int u;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();
        d_u = temp.first;
        u = temp.second;
        if (d_u != dist[u]) continue;
        for (const auto &[v, w] : AL[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u]+w;
                dp[v] = dp[u];
                pq.push({dist[v],v});
            }
            else if (dist[u] + w == dist[v]) {
                dp[v] = (dp[v] + dp[u]) % MOD;
            }
        }
    }
}

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        memset(dp, 0, sizeof dp);
        memset(dist, 0, sizeof dist);
        decltype(AL)().swap(AL);
        AL.resize(n);
        int u,v;
        ll w;
        for (auto &i : roads) {
            u = i[0];
            v = i[1];
            w = i[2];
            AL[u].emplace_back(v,w);
            AL[v].emplace_back(u,w);
        }
        dijkstra();
        return dp[n-1] % MOD;
    }
};