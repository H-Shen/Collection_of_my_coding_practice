// https://open.kattis.com/problems/molekule
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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

namespace BipartiteCheck {
    constexpr int INF = 0x3f3f3f3f;
    vector<int> color;
    vector<unordered_set<int, custom_hash> > adj;
    int n;
    void init(int number_of_nodes) {
        n = number_of_nodes;
        decltype(adj)().swap(adj);
        decltype(color)().swap(color);
        adj.resize(n + 5);
        color.resize(n + 5, INF);
    }
    bool bfs() {
        queue<int> q;
        for (int s = 1; s <= n; ++s) {
            if (color[s] == INF) {
                color[s] = 0;
                q.push(s);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const auto &v : adj[u]) {
                    if (color[v] == INF) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}


int main() {

    int n, u, v;
    IO::read(n);
    BipartiteCheck::init(n);
    vector<pii> edges(n - 1);
    for (int i = 1; i <= n - 1; ++i) {
        IO::read(u, v);
        BipartiteCheck::adj.at(u).insert(v);
        BipartiteCheck::adj.at(v).insert(u);
        edges.at(i - 1) = {u, v};
    }
    BipartiteCheck::bfs();
    // contains all edges from 0 to 1
    for (const auto &i : edges) {
        if (BipartiteCheck::color.at(i.first) == 1 && BipartiteCheck::color.at(i.second) == 0) {
            IO::writeln(1);
        } else {
            IO::writeln(0);
        }
    }

    return 0;
}
