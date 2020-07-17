// https://open.kattis.com/problems/shortestpath3
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

// An implementation of Bellman-Ford's algorithm
namespace SSSP2 {
    constexpr int INF = 0x3f3f3f3f;
    struct Edge {
        int u, v;
        int w;
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };
    vector<int> dis;
    vector<Edge> edges;
    int number_of_nodes;
    int source;

    inline void
    reset() {
        vector<int>().swap(dis);
        vector<Edge>().swap(edges);
        number_of_nodes = 0;
        source = 0;
    }

    inline void
    init(int n, int s) {
        number_of_nodes = n;
        source = s;
        dis.resize(n + 5, INF);
        dis.at(source) = 0;
    }

    inline void
    relax(const Edge &e) {
        if (dis.at(e.v) > dis.at(e.u) + e.w) {
            dis.at(e.v) = dis.at(e.u) + e.w;
        }
    }

    // The main logic of the algorithm
    inline void
    bellman_ford() {
        for (int i = 1; i <= number_of_nodes - 1; ++i) {
            for (const auto &e : edges) {
                if (dis.at(e.u) < INF) {
                    relax(e);
                }
            }
        }
        for (int i = 1; i <= number_of_nodes - 1; ++i) {
            for (auto &e : edges) {
                if (dis.at(e.u) == -INF) {
                    dis.at(e.v) = -INF;
                } else if (dis.at(e.u) < INF && dis.at(e.v) > dis.at(e.u) + e.w) {
                    dis.at(e.v) = -INF;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {

    int n, m, q, s, u, v, w;
    bool first_case = true;
    while (true) {
        IO::read(n, m, q, s);
        if (n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }
        if (first_case) {
            first_case = false;
        } else {
            putchar_unlocked('\n');
        }
        SSSP2::init(n, s);
        for (int i = 0; i < m; ++i) {
            IO::read(u, v, w);
            SSSP2::edges.emplace_back(SSSP2::Edge(u, v, w));
        }
        SSSP2::bellman_ford();
        for (int i = 0; i < q; ++i) {
            IO::read(u);
            if (u >= n) {   // trivial case
                fputs("Impossible\n", stdout);
            } else if (SSSP2::dis.at(u) == -SSSP2::INF) {
                fputs("-Infinity\n", stdout);
            } else if (SSSP2::dis.at(u) == SSSP2::INF) {
                fputs("Impossible\n", stdout);
            } else {
                IO::writeln(SSSP2::dis.at(u));
            }
        }
        SSSP2::reset();
    }
    return 0;
}
