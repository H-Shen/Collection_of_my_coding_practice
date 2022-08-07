using ll = long long;

constexpr ll INF = 0x3f3f3f3f3f3f;

class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = (int)regular.size()+1;
        vector<vector<pair<int,ll>>> adj(2*n);
        int index = 0;
        int u,v;
        ll w;
        for (int i = 0; i < n-1; ++i) {
            u = i;
            v = u+1;
            w = regular[i];
            adj[u].emplace_back(v,w);
        }
        for (int i = 0; i < n-1; ++i) {
            u = i+n;
            v = u+1;
            w = express[i];
            adj[u].emplace_back(v,w);
        }
        for (int i = 0; i < n; ++i) {
            u = i;
            v = i+n;
            adj[u].emplace_back(v,expressCost);
            adj[v].emplace_back(u,0);
        }
        // dijkstra
        vector<ll> d1(2*n, INF); // src: 0
        d1[0] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq1;
        pq1.push({d1[0], 0});
        while (!pq1.empty()) {
            auto p = pq1.top();
            pq1.pop();
            ll d_u = p.first;
            int u = p.second;
            if (d_u != d1[u]) {
                continue;
            }
            for (const auto &[v, w] : adj[u]) {
                if (d1[u] + w < d1[v]) {
                    d1[v] = d1[u] + w;
                    pq1.push({d1[v], v});
                }
            }
        }
    
        
        vector<ll> d2(2*n, INF); // src: n
        d2[n] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq2;
        pq2.push({d2[0], 0});
        while (!pq2.empty()) {
            auto p = pq2.top();
            pq2.pop();
            ll d_u = p.first;
            int u = p.second;
            if (d_u != d2[u]) {
                continue;
            }
            for (const auto &[v, w] : adj[u]) {
                if (d2[u] + w < d2[v]) {
                    d2[v] = d2[u] + w;
                    pq1.push({d2[v], v});
                }
            }
        }
        
        vector<ll> ans(n-1);
        for (int i = 1; i < n; ++i) {
            ans[i-1] = min(d1[i], d2[n+i]);
        }
        
        return ans;
    }
};