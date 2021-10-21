// https://open.kattis.com/problems/tripplanning

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
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
        static const uint64_t FIXED_RANDOM =
                std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, m, u, v;
vector<gp_hash_table<int, int, custom_hash>> adj;
vector<int> ans;

int main() {
    IO::read(n, m);
    adj.resize(n+1);
    for (int i = 1; i <= m; ++i) {
        IO::read(u,v);
        adj[u][v] = i;
        adj[v][u] = i;
    }
    for (int i = 1; i < n; ++i) {
        u = i;
        v = i+1;
        if (adj[u].find(v) == adj[u].end()) {
            puts("impossible");
            return 0;
        }
        ans.emplace_back(adj[u][v]);
    }
    u = n;
    v = 1;
    if (adj[u].find(v) == adj[u].end()) {
        puts("impossible");
        return 0;
    }
    ans.emplace_back(adj[u][v]);
    for (auto &i : ans) {
        IO::writeln(i);
    }
    return 0;
}
