#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }

    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }

    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

constexpr ll INF = 4e18;
using edge = tuple<int, ll, ll>;
class Maxflow {
private:
    int n;
    vector<edge> el;
    vector<vector<int> > adj;
    vector<int> d, last;
    vector<pair<int, int> > p;
    bool bfs(int s, int t) {                       // find augmenting path
        d.assign(n, -1); d[s] = 0;
        queue<int> q({s});
        p.assign(n, {-1, -1});                       // record bfs sp tree
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;                         // stop as sink t reached
            for (auto &idx : adj[u]) {                  // explore neighbors of u
                auto &[v, cap, flow] = el[idx];          // stored in el[idx]
                if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
                    d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1;                           // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
        if (s == t) return f;                        // bottleneck edge f found
        auto &[u, idx] = p[t];
        auto &cap = get<1>(el[idx]), &flow = get<2>(el[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap-flow));
        flow += pushed;
        auto &rflow = get<2>(el[idx ^ 1]);             // back edge
        rflow -= pushed;                             // back flow
        return pushed;
    }

    ll dfs(int u, int t, ll f = INF) {             // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)adj[u].size(); ++i) { // from last edge
            auto &[v, cap, flow] = el[adj[u][i]];
            if (d[v] != d[u]+1) continue;              // not part of layer graph
            if (ll pushed = dfs(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(el[adj[u][i] ^ 1]);     // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

public:
    Maxflow(int number_of_nodes) : n(number_of_nodes) {
        adj.resize(n);
    }
    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        el.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
        adj[u].push_back(el.size() - 1);                // remember this index
        el.emplace_back(u, directed ? 0 : w, 0);     // back edge
        adj[v].push_back(el.size() - 1);                // remember this index
    }
    ll dinic(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (bfs(s, t)) {                          // an O(n^2*E) algorithm
            last.assign(n, 0);                         // important speedup
            while (ll f = dfs(s, t))                   // exhaust blocking flow
                mf += f;
        }
        return mf;
    }
};

int main() {
    int n, m, s, t, u, v;
    ll w;
    IO::read(n, m, s, t);
    --s;
    --t;
    Maxflow maxflow(n);
    while (m--) {
        IO::read(u, v, w);
        --u;
        --v;
        maxflow.add_edge(u, v, w);
    }
    IO::writeln(maxflow.dinic(s, t));
    return 0;
}