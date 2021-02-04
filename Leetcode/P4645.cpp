#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;

constexpr int MAXN = 10005;
constexpr ll MOD = 1e9;
vector<vector<int> > adj, adj_rev;
vector<int> in_degree;

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

bitset<MAXN> vis_from_1, vis_from_2, both_vis;

void bfs_from_1() {
    queue<int> q;
    q.push(1);
    vis_from_1[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &v : adj[u]) {
            if (!vis_from_1[v]) {
                vis_from_1[v] = true;
                q.push(v);
            }
        }
    }
}
void bfs_from_2() {
    queue<int> q;
    q.push(2);
    vis_from_2[2] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &v : adj_rev[u]) {
            if (!vis_from_2[v]) {
                vis_from_2[v] = true;
                q.push(v);
            }
        }
    }
}

ll dp[MAXN];
int elements_visited_by_both;

void toposort() {
    queue<int> q;
    q.push(1);
    dp[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++elements_visited_by_both;
        for (const auto &v : adj[u]) {
            if (both_vis[v]) {
                dp[v] = (dp[v] % MOD + dp[u] % MOD) % MOD;
                --in_degree[v];
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
}

int main() {

    int n, m, u, v;
    IO::read(n, m);
    adj.resize(n + 5);
    adj_rev.resize(n + 5);
    in_degree.resize(n + 5);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v);
        adj.at(u).emplace_back(v);
        adj_rev.at(v).emplace_back(u);
    }
    bfs_from_1();
    bfs_from_2();
    for (int i = 1; i <= n; ++i) {
        if (vis_from_1[i] && vis_from_2[i]) {
            both_vis[i] = true;
        }
    }
    int counter = 0;
    for (int i = 1; i <= n; ++i) {
        if (both_vis[i]) {
            ++counter;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (both_vis[i]) {
            for (const auto &j : adj[i]) {
                ++in_degree[j];
            }
        }
    }
    toposort();
    if (elements_visited_by_both != counter) {
        puts("inf");
        return 0;
    }
    ll result = dp[2] % MOD;
    IO::writeln(result);

    return 0;
}