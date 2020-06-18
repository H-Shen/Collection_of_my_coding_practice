// https://open.kattis.com/problems/dominoes2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 10005;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
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

unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;
bitset<MAXN> vis;
int counter;

void dfs(int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = true;
    ++counter;
    if (G.find(u) == G.end()) {
        return;
    }
    for (const auto &adj : G[u]) {
        dfs(adj);
    }
}

int main() {

    int t, n, m, l, u, v;
    IO::read(t);
    while (t--) {
        IO::read(n, m, l);
        vis.reset();
        G.clear();
        counter = 0;
        while (m--) {
            IO::read(u, v);
            G[u].insert(v);
        }
        while (l--) {
            IO::read(u);
            dfs(u);
        }
        IO::writeln(counter);
    }

    return 0;
}
