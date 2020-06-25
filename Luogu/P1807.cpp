// Example of how to obtain the distance of longest path in a DAG with a given destination

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

constexpr int MAXN = 1505;
constexpr ll INF = 0x3f3f3f3f3f;
vector<gp_hash_table<int, ll, custom_hash> > G(MAXN);

ll dp[MAXN];
bitset<MAXN> vis;

ll solve(int node_id) {
    // Case 1:
    if (vis[node_id]) {
        return dp[node_id];
    }
    // Case 2:
    vis[node_id] = true;
    for (const auto &[adj_node_id, adj_edge_weight] : G[node_id]) {
        if (adj_edge_weight != INF) {
            dp[node_id] = max(dp[node_id],
                              solve(adj_node_id) + adj_edge_weight);
        }
    }
    return dp[node_id];
}

int main() {

    int n, m;
    IO::read(n, m);
    int u, v;
    ll w;
    // add edges
    while (m--) {
        IO::read(u, v, w);
        G[u][v] = max(G[u][v], w);
    }
    // add edges for each node from self to self
    for (int i = 1; i <= n; ++i) {
        G[i][i] = max(G[i][i], 0LL);
    }
    // start dp
    fill(dp, dp + MAXN, -INF);
    dp[n] = 0;
    ll answer = solve(1);
    if (!vis[n]) {
        answer = -1;
    }
    IO::writeln(answer);

    return 0;
}
