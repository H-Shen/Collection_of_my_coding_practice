#include <bits/stdc++.h>

using namespace std;
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

// An implementation of Floyd_Warshall Algorithm O(n^3) for finding
// all pairs of shortest path in a graph
namespace APSP_Floyd_Warshall {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > am; // adjacency matrix
    int n;
    void init(int number_of_nodes) {
        // reset
        vector<vector<int> >().swap(am);
        n = number_of_nodes;
        am.resize(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            am[i][i] = 0;   // true on most cases
        }
    }
    void floyd_warshall() { // order: k, i, j
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (am[i][k] < INF && am[k][j] < INF)
                        am[i][j] = min(am[i][j], am[i][k]+am[k][j]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int t = 0; t < n; ++t)
                    if (am[i][t] < INF && am[t][t] < 0 && am[t][j] < INF)
                        am[i][j] = -INF;
    }
    // Query the shortest distance from u to v
    // INF: cant reach -INF: in a negative cycle
    int dist(const int &u, const int &v) {
        return am[u][v];
    }
}

int main() {

    int t, n, m, u, v, s, d;
    IO::read(t);
    for (int kase = 1; kase <= t; ++kase) {
        IO::read(n, m);
        APSP_Floyd_Warshall::init(n);
        while (m--) {
            IO::read(u, v);
            APSP_Floyd_Warshall::am[u][v] = 1;
            APSP_Floyd_Warshall::am[v][u] = 1;
        }
        IO::read(s, d);
        APSP_Floyd_Warshall::floyd_warshall();
        int maxVal = -1;
        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, APSP_Floyd_Warshall::dist(s, i) + APSP_Floyd_Warshall::dist(i, d));
        }
        printf("Case %d: %d\n", kase, maxVal);
    }
    
    return 0;
}