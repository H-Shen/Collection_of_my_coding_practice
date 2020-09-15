// dfs with back-track
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;

constexpr int MAXN = 25;

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

int n, m;
vector<vector<pii> > adj;
bitset<MAXN> vis;
int max_length;

void dfs(int u, int dist) {
    max_length = max(max_length, dist);
    for (const auto &[v, w] : adj.at(u)) {
        if (!vis[v]) {
            // back-track
            vis[v] = true;
            dfs(v, dist + w);
            vis[v] = false;
        }
    }
}

int main() {

    IO::read(n, m);
    adj.resize(n + 5);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        adj.at(u).emplace_back(v, w);
        adj.at(v).emplace_back(u, w);
    }
    for (int i = 1; i <= n; ++i) {
        vis[i] = true;
        dfs(i, 0);
        vis.reset();
    }
    IO::writeln(max_length);

    return 0;
}
