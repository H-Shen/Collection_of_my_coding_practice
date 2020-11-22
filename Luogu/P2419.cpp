#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

constexpr int MAXN = 105;

template<size_t N>
struct TransitiveClosure {
    bitset<N> reach[N];
    void floyd_warshall(int n) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                if (reach[i][k]) {
                    reach[i] |= reach[k];    // reach[i] = reach[i] | reach[k];
                }
            }
        }
    }
};

int main()
{
    TransitiveClosure<MAXN> tc;
    int n, m, u, v;
    IO::read(n, m);
    for (int i = 1; i <= n; ++i) {
        tc.reach[i][i] = true;
    }
    while (m--) {
        IO::read(u, v);
        tc.reach[u][v] = true;  // u beats v
    }
    tc.floyd_warshall(n);
    int counter = 0;
    bool haveAns;
    for (int i = 1; i <= n; ++i) {
        haveAns = true;
        for (int j = 1; j <= n; ++j) {
            if (!tc.reach[i][j] && !tc.reach[j][i]) {
                haveAns = false;
                break;
            }
        }
        if (haveAns) {
            ++counter;
        }
    }
    IO::writeln(counter);

    return 0;
}