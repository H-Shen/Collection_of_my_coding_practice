using ll = long long;

// Min Cost Max Flow
namespace MCMF {
    using edge = tuple<int,ll,ll,ll>;
    constexpr ll INF = 1e18;
    int v;
    ll totalCost;
    vector<edge> EL;
    vector<vector<int> > AL;
    vector<ll> d;
    vector<int> last;
    vector<bool> vis;

    void reset() {
        v = 0;
        totalCost = 0;
        decltype(EL)().swap(EL);
        decltype(AL)().swap(AL);
        decltype(d)().swap(d);
        decltype(last)().swap(last);
        decltype(vis)().swap(vis);
    }

    void init(int n) {
        reset();
        v = n;
        d.resize(v);
        vis.resize(v, false);
        AL.resize(v);
        last.resize(v);
    }

    // SPFA to find if there is an augmenting path in residual graph
    bool spfa(int s, int t) {
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        vis[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (const auto &idx : AL[u]) {
                auto &[v, cap, flow, cost] = EL[idx];
                if (cap > flow && d[v] > d[u] + cost) {
                    d[v] = d[u] + cost;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return d[t] != INF;
    }

    ll dfs(int u, int t, ll f = INF) {
        if (u == t || f == 0) {
            return f;
        }
        vis[u] = true;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i) {
            auto &[v, cap, flow, cost] = EL[AL[u][i]];
            if (!vis[v] && d[v] == d[u] + cost) {
                if (ll pushed = dfs(v, t, min(f, cap - flow))) {
                    totalCost += pushed * cost;
                    flow += pushed;
                    auto &[rv, rcap, rflow, rcost] = EL[AL[u][i]^1];    // back edge
                    rflow -= pushed;
                    vis[u] = false;
                    return pushed;
                }
            }
        }
        vis[u] = false;
        return 0;
    }

    void addEdge(int u, int v, ll w, ll c, bool directed = true) {
        if (u == v) {
            return;
        }
        EL.emplace_back(v, w, 0, c);
        AL[u].emplace_back((int)EL.size() - 1);
        EL.emplace_back(u, directed ? 0 : w, 0, -c);
        AL[v].emplace_back((int)EL.size() - 1);
    }

    pair<ll,ll> mcmf(int s, int t) {
        ll mf = 0;
        while (spfa(s, t)) {
            fill(last.begin(), last.end(), 0);
            while (ll f = dfs(s,t)) {
                mf += f;
            }
        }
        return {mf, totalCost};
    }
}

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // Weighted Minimum Cardinality Bipartite Matching -> Min Cost Max Flow
        // UVA10746
        int m = (int)bikes.size();
        int n = (int)workers.size();
        // give all workers and bikes id from 1 to m+n, workers have id from 1 to n, bikes have id from n+1 to n+m
        MCMF::init(m+n+2);
        // s=0 to n workers (cap=1 cost=0)
        for (int i = 1; i <= n; ++i) {
            MCMF::addEdge(0,i,1,0);
        }
        // n workers to m bikes
        int u, v;
        ll dist;
        for (int i = 1; i <= n; ++i) {
            for (int j = n+1; j <= n+m; ++j) {
                u = i-1;
                v = j-n-1;
                dist = abs(workers[u][0]-bikes[v][0])+abs(workers[u][1]-bikes[v][1]);
                MCMF::addEdge(i,j,1,dist);
            }
        }
        
        // m bikes to t=m+n+1 (cap=1 cost=0)
        for (int i = n+1; i <= n+m; ++i) {
            MCMF::addEdge(i,m+n+1,1,0);
        }
        auto ans = MCMF::mcmf(0,m+n+1);
        return ans.second;
    }
};