// https://open.kattis.com/problems/allpairspath
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

namespace Floyd {
    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAXN = 155;
    int d[MAXN][MAXN];
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = INF;
                }
            }
        }
    }
    void process(int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][k] < INF && d[k][j] < INF) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t < n; ++t) {
                    if (d[i][t] < INF && d[t][t] < 0 && d[t][j] < INF)
                        d[i][j] = -INF;
                }
            }
        }
    }
}

int n, m, q, u, v, w;

int main() {

    bool firstCase = true;
    while (true) {
        IO::read(n, m, q);
        if (n == 0 && m == 0 && q == 0) {
            break;
        }
        Floyd::init(n);
        while (m--) {
            IO::read(u, v, w);
            Floyd::d[u][v] = min(Floyd::d[u][v], w);
        }
        Floyd::process(n);
        if (firstCase) {
            firstCase = false;
        } else {
            putchar_unlocked('\n');
        }
        while (q--) {
            IO::read(u, v);
            if (Floyd::d[u][v] == Floyd::INF) {
                puts("Impossible");
            } else if (Floyd::d[u][v] == -Floyd::INF) {
                puts("-Infinity");
            } else {
                IO::writeln(Floyd::d[u][v]);
            }
        }
    }

    return 0;
}
