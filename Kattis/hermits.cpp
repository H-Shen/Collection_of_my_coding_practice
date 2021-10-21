// https://open.kattis.com/problems/hermits

#include <bits/extc++.h>

using namespace std;
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

constexpr int MAXN = 1005;
int weight[MAXN];
vector<int> adj[MAXN];
int n, m, u, v;

int main() {
    IO::read(n);
    for (int i = 1; i <= n; ++i) {
        IO::read(weight[i]);
    }
    IO::read(m);
    while (m--) {
        IO::read(u,v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int minVal = numeric_limits<int>::max();
    int sum;
    for (int i = 1; i <= n; ++i) {
        sum = weight[i];
        for (const auto &j : adj[i]) {
            sum += weight[j];
        }
        minVal = min(minVal, sum);
    }
    for (int i = 1; i <= n; ++i) {
        sum = weight[i];
        for (const auto &j : adj[i]) {
            sum += weight[j];
        }
        if (minVal == sum) {
            IO::writeln(i);
            return 0;
        }
    }
    return 0;
}
