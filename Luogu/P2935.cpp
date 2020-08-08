#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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

namespace APSP_Floyd_Warshall {

    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > adj_matrix; // adjacency matrix
    int number_of_nodes;

    inline
    void init(int n) {
        // reset
        vector<vector<int> >().swap(adj_matrix);
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes + 5,
                          vector<int>(number_of_nodes + 5, INF));
        for (int i = 0; i < number_of_nodes + 5; ++i) {
            adj_matrix.at(i).at(i) = 0;
        }
    }

    inline
    void floyd_warshall() {
        for (int k = 0; k < number_of_nodes + 5; ++k) {
            for (int i = 0; i < number_of_nodes + 5; ++i) {
                for (int j = 0; j < number_of_nodes + 5; ++j) {
                    if (adj_matrix.at(i).at(k) < INF &&
                        adj_matrix.at(k).at(j) < INF) {
                        adj_matrix.at(i).at(j) = min(adj_matrix.at(i).at(j),
                                                     adj_matrix.at(i).at(k) +
                                                     adj_matrix.at(k).at(j));
                    }
                }
            }
        }
    }
}

int main() {

    int p, f, c, u, v, w;
    IO::read(p, f, c);
    APSP_Floyd_Warshall::init(p);
    vector<int> pref(f);
    for (auto &i : pref) IO::read(i);
    while (c--) {
        IO::read(u, v, w);
        APSP_Floyd_Warshall::adj_matrix.at(u).at(v) = w;
        APSP_Floyd_Warshall::adj_matrix.at(v).at(u) = w;
    }
    APSP_Floyd_Warshall::floyd_warshall();
    ll total_min_dist = numeric_limits<ll>::max();
    for (int i = 1; i <= p; ++i) {
        ll dist = 0;
        for (const auto &j : pref) {
            dist += APSP_Floyd_Warshall::adj_matrix.at(i).at(j);
        }
        total_min_dist = min(total_min_dist, dist);
    }
    for (int i = 1; i <= p; ++i) {
        ll dist = 0;
        for (const auto &j : pref) {
            dist += APSP_Floyd_Warshall::adj_matrix.at(i).at(j);
        }
        if (dist == total_min_dist) {
            IO::writeln(i);
            break;
        }
    }

    return 0;
}