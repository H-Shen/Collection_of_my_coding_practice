#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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

namespace MCBM {
    const int MAXN = 505;
    const int MAXM = 500005;
    struct Edge {
        int to, next;
    } edge[MAXM];
    int head[MAXN];
    int tot;

    void init() {
        tot = 0;
        memset(head, -1, sizeof(head));
    }

    void addedge(int u, int v) {
        edge[tot].to = v;
        edge[tot].next = head[u];
        head[u] = tot++;
    }

    int linker[MAXN];
    int linker_rev[MAXN];
    bool used[MAXN];
    int uN;

    bool dfs(int u) {
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if (!used[v]) {
                used[v] = true;
                if (linker[v] == -1 || dfs(linker[v])) {
                    linker_rev[u] = v;
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int hungary() {
        int res = 0;
        memset(linker, -1, sizeof(linker));
        for (int u = 0; u < uN; u++) {
            memset(used, false, sizeof(used));
            if (dfs(u))res++;
        }
        return res;
    }
}

int main() {
    int n, m, e;
    IO::read(n, m, e);
    MCBM::init();
    MCBM::uN = n;
    int u, v;
    while (e--) {
        IO::read(u, v);
        --u;
        --v;
        MCBM::addedge(u, v);
    }
    IO::writeln(MCBM::hungary());
    return 0;
}