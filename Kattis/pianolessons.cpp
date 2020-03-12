#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace MCBM {
    constexpr int MAX_NODES = 1005;
    int uN, vN;
    int g[MAX_NODES][MAX_NODES];
    int linker[MAX_NODES];
    bool used[MAX_NODES];
    bool dfs(int u) {
        for (int v = 0; v < vN; ++v) {
            if (g[u][v] && !used[v]) {
                used[v] = true;
                if(linker[v] == -1 || dfs(linker[v])){
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
        for (int u = 0; u < uN; ++u) {
            memset(used, false, sizeof(used));
            if (dfs(u)) {
                ++res;
            }
        }
        return res;
    }
}

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
        puts("");
    }
}

int main() {

    int n, m, t, v;
    IO::read(n, m);
    for (int i = 0; i < n; ++i) {
        IO::read(t);
        while (t--) {
            IO::read(v);
            MCBM::g[i][v - 1] = 1;
        }
    }
    MCBM::uN = n;
    MCBM::vN = m;
    IO::writeln(MCBM::hungary());

    return 0;
}
