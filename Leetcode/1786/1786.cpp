using ll = long long;
constexpr ll MOD = 1e9+7;
constexpr ll INF = 4e18;

vector<vector<pair<int,ll>>> AL;
vector<ll> dist;
vector<vector<int>> AL2;
vector<ll> dp;

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({dist[src],src});
    pair<ll,int> p;
    ll d_u;
    int u;
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        d_u = p.first;
        u = p.second;
        if (d_u != dist[u]) continue;
        for (const auto &[v,w] : AL[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
}

ll solve(int u) {
   if (dp[u] != INF) {
       return dp[u];
   }
   dp[u] = 0;
   for (const auto &v : AL2[u]) {
       dp[u] = (dp[u] + solve(v)) % MOD;
   }
   return dp[u];
}

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        decltype(AL)().swap(AL);
        AL.resize(n+1);
        int u,v;
        ll w;
        for (const auto &i : edges) {
            u = i[0];
            v = i[1];
            w = i[2];
            AL[u].emplace_back(v,w);
            AL[v].emplace_back(u,w);
        }
        decltype(dist)().swap(dist);
        dist.resize(n+1, INF);
        dijkstra(n);
        decltype(AL2)().swap(AL2);
        AL2.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            u = i;
            for (const auto &[j,_] : AL[u]) {
                v = j;
                if (dist[u] > dist[v]) {
                    AL2[v].emplace_back(u);
                }
            }
        }
        decltype(dp)().swap(dp);
        dp.resize(n+1, INF);
        dp[1] = 1;
        return (int)(solve(n) % MOD);
    }
};