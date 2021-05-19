#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static const double EPS = 1e-7;

// Min Cost Max Flow
namespace MCMF {
    using edge = tuple<int, ll, ll, double>;
    constexpr double INF = 1e9;
    int n;
    double totalCost;
    vector<edge> EL;
    vector<vector<int> > AL;
    vector<double> d;
    vector<int> last;
    vector<bool> vis;

    void reset() {
        n = 0;
        totalCost = 0.0;
        decltype(EL)().swap(EL);
        decltype(AL)().swap(AL);
        decltype(d)().swap(d);
        decltype(last)().swap(last);
        decltype(vis)().swap(vis);
    }

    void init(int n_) {
        reset();
        n = n_;
        d.resize(n);
        vis.resize(n);
        AL.resize(n);
        last.resize(n);
    }

    int sgn(const double &x) {
        if (x > EPS) return 1;
        if (x > -EPS) return 0;
        return -1;
    }

    // SPFA to find if there is an augmenting path
    // in residual graph
    bool spfa(int s, int t) {
        fill(d.begin(), d.end(), INF);
        d[s] = 0.0;
        vis[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (const auto &idx : AL[u]) {
                auto &v = get<0>(EL[idx]);
                auto &cap = get<1>(EL[idx]);
                auto &flow = get<2>(EL[idx]);
                auto &cost = get<3>(EL[idx]);
                if (cap > flow && sgn(d[v] - (d[u]+cost)) > 0) {
                    d[v] = d[u] + cost;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return sgn(d[t]-INF) != 0;
    }

    ll dfs(int u, int t, ll f = INF) {
        if (u == t || f == 0) {
            return f;
        }
        vis[u] = true;
        for (int &i = last[u]; i < (int) AL[u].size(); ++i) {
            auto &v = get<0>(EL[AL[u][i]]);
            auto &cap = get<1>(EL[AL[u][i]]);
            auto &flow = get<2>(EL[AL[u][i]]);
            auto &cost = get<3>(EL[AL[u][i]]);
            if (!vis[v] && d[v] == d[u] + cost) {
                if (ll pushed = dfs(v, t, min(f, cap - flow))) {
                    totalCost += pushed * 1.0 * cost;
                    flow += pushed;
                    auto &rv = get<0>(EL[AL[u][i] ^ 1]);
                    auto &rcap = get<1>(EL[AL[u][i] ^ 1]);
                    auto &rflow = get<2>(EL[AL[u][i] ^ 1]);
                    auto &rcost = get<3>(EL[AL[u][i] ^ 1]);
                    rflow -= pushed;
                    vis[u] = false;
                    return pushed;
                }
            }
        }
        vis[u] = false;
        return 0;
    }

    void addEdge(int u, int v, ll w, double c,
                 bool directed = true) {
        if (u == v) {
            return;
        }
        EL.emplace_back(v, w, 0, c);
        AL[u].emplace_back((int) EL.size() - 1);
        EL.emplace_back(u, directed ? 0 : w, 0, -c);
        AL[v].emplace_back((int) EL.size() - 1);
    }

    pair<ll, double> mcmf(int s, int t) {
        ll mf = 0;
        while (spfa(s, t)) {
            fill(last.begin(), last.end(), 0);
            while (ll f = dfs(s, t)) {
                mf += f;
            }
        }
        return {mf, totalCost};
    }
}

int main() {
    int n, m;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        vector<vector<double> > dist(n, vector<double>(m));
        for (auto &i : dist) for (auto &j : i) scanf("%lf", &j);
        // s = 0
        // 1 to n --> 1 to n
        // 1 to m --> n+1 to n+m
        // t = n+m+1
        MCMF::init(n+m+2);
        for (int i = 1; i <= n; ++i) {
            MCMF::addEdge(0,i,1,0.0);
        }
        for (int i = n+1; i <= n+m; ++i) {
            MCMF::addEdge(i,n+m+1, 1, 0.0);
        }
        int u, v;
        for (int i = 1; i <= n; ++i) {
            for (int j = n+1; j <= n+m; ++j) {
                u = i - 1;
                v = j - n - 1;
                MCMF::addEdge(i,j,1,dist[u][v]);
            }
        }
        auto p = MCMF::mcmf(0,n+m+1);
        printf("%.2lf\n", p.second / n + EPS);
    }

    return 0;
}