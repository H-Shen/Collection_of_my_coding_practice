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

// An implementation of Floyd_Warshall Algorithm O(n^3) for finding
// all pairs of shortest path in a graph
namespace APSP0 {

    constexpr int INF = 0x3f3f3f3f;

    vector<vector<int> > adj_matrix; // adjacency matrix
    int number_of_nodes;

    inline
    void init(int n) {
        // reset
        vector<vector<int> >().swap(adj_matrix);
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes, vector<int>(number_of_nodes));
        for (int i = 0; i < number_of_nodes; ++i) {
            for (int j = 0; j < number_of_nodes; ++j) {
                adj_matrix.at(i).at(j) = INF;
            }
        }
        for (int i = 0; i < number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0;
        }
    }

    inline
    void floyd_warshall() {
        for (int k = 0; k < number_of_nodes; ++k) {
            for (int i = 0; i < number_of_nodes; ++i) {
                for (int j = 0; j < number_of_nodes; ++j) {
                    if (adj_matrix.at(i).at(k) < INF &&
                        adj_matrix.at(k).at(j) < INF) {
                        adj_matrix.at(i).at(j) = min(adj_matrix.at(i).at(j),
                                                     adj_matrix.at(i).at(k) +
                                                     adj_matrix.at(k).at(j));
                    }
                }
            }
        }
        for (int i = 0; i < number_of_nodes; ++i) {
            for (int j = 0; j < number_of_nodes; ++j) {
                for (int t = 0; t < number_of_nodes; ++t) {
                    if (adj_matrix.at(i).at(t) < INF &&
                        adj_matrix.at(t).at(t) < 0 &&
                        adj_matrix.at(t).at(j) < INF) {
                        adj_matrix.at(i).at(j) = -INF;
                    }
                }
            }
        }
    }

    // Query the shortest distance from node u to node v
    inline
    int dist(const int &u, const int &v) {
        return adj_matrix.at(u).at(
                v);  // INF: cant reach -INF: in a negative cycle
    }
}

int n, m, q, u, v, w, ans;

int main() {

    bool first_case = true;
    while (true) {
        IO::read(n, m, q);
        if (n == 0 && m == 0 && q == 0) {
            break;
        }
        APSP0::init(n);
        while (m--) {
            IO::read(u, v, w);
            // Update the shortest weight between u and v
            APSP0::adj_matrix.at(u).at(v) = min(APSP0::adj_matrix.at(u).at(v),
                                                w);
        }
        APSP0::floyd_warshall();
        if (first_case) {
            first_case = false;
        } else {
            putchar_unlocked('\n');
        }
        while (q--) {
            IO::read(u, v);
            ans = APSP0::dist(u, v);
            if (u < 0 || u >= n || v < 0 || v >= n || ans == APSP0::INF) {
                fputs_unlocked("Impossible\n", stdout);
            } else if (ans == -APSP0::INF) {
                fputs_unlocked("-Infinity\n", stdout);
            } else {
                IO::writeln(ans);
            }
        }
    }
    return 0;
}
