#include <bits/extc++.h>

using namespace std;
using ll = long long;

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

constexpr int MOD = 100003;
constexpr int INF = 0x3f3f3f3f;

int n, m, s;
vector<vector<int> > AL;
vector<int> cnt;
vector<int> dist;

void dijkstra() {
    dist.resize(n+1, INF);
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
    pq.push({dist[s],s});
    cnt[s] = 1;
    while (!pq.empty()) {
        int d_u = pq.top().first;
        int u = pq.top().second;
        if (d_u != dist[u]) continue;
        pq.pop();
        for (const auto &v : AL[u]) {
            if (dist[u] + 1 == dist[v]) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
            else if (dist[u] + 1 < dist[v]) {
                cnt[v] = cnt[u];
                dist[v] = dist[u] + 1;
                pq.push({dist[v],v});
            }
        }
    }
}

int main() {
    IO::read(n, m);
    AL.resize(n+1);
    cnt.resize(n+1);
    s = 1;
    int u, v;
    while (m--) {
        IO::read(u,v);
        AL[u].emplace_back(v);
        AL[v].emplace_back(u);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            IO::writeln(0);
        } else {
            IO::writeln(cnt[i] % MOD);
        }
    }
    return 0;
}