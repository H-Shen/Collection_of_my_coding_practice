// https://open.kattis.com/problems/popularitycontest

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
int n, m;
int deg[MAXN];  // can safely ignore duplicated edges here

int main() {
    IO::read(n,m);
    int u,v;
    while (m--) {
        IO::read(u,v);
        ++deg[u];
        ++deg[v];
    }
    for (int i = 1; i <= n; ++i) {
        IO::write(deg[i]-i);
        putchar_unlocked(' ');
    }
    return 0;
}
