// Query the shortest path with selected nodes
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

namespace APSP_Floyd_Warshall {

    constexpr int INF = 0x3f3f3f3f;

    vector<vector<int> > adj_matrix; // adjacency matrix
    int number_of_nodes;

    inline
    void init(int n) {
        // reset
        vector<vector<int> >().swap(adj_matrix);
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes + 5, vector<int>(number_of_nodes + 5, INF));
        for (int i = 1; i <= number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0;
        }
    }

    inline
    void floyd_warshall() {
        for (int k = 1; k <= number_of_nodes; ++k) {
            for (int i = 1; i <= number_of_nodes; ++i) {
                for (int j = 1; j <= number_of_nodes; ++j) {
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

    // Query the shortest distance from node u to node v
    inline
    int dist(const int &u, const int &v) {
        return adj_matrix.at(u).at(
                v);  // INF: cant reach -INF: in a negative cycle
    }
}

int main() {

    int n, temp, p;
    IO::read(n);
    APSP_Floyd_Warshall::init(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            IO::read(temp);
            APSP_Floyd_Warshall::adj_matrix.at(i).at(j) = min(temp, APSP_Floyd_Warshall::adj_matrix.at(i).at(j));
        }
    }
    APSP_Floyd_Warshall::floyd_warshall();
    vector<int> positions_of_treasure;
    IO::read(p);
    for (int i = 0; i < p; ++i) {
        IO::read(temp);
        if (temp > 1 && temp < n) {
            positions_of_treasure.emplace_back(temp);
        }
    }
    if (positions_of_treasure.empty()) {
        IO::writeln(APSP_Floyd_Warshall::dist(1, n));
    } else {
        ll min_dist = APSP_Floyd_Warshall::INF;
        ll dist;
        // Enumerate all possible orders
        sort(positions_of_treasure.begin(), positions_of_treasure.end());
        do {
            dist = 0;
            dist += APSP_Floyd_Warshall::dist(1, positions_of_treasure.front());
            for (size_t i = 0; i != positions_of_treasure.size() - 1; ++i) {
                dist += APSP_Floyd_Warshall::dist(positions_of_treasure.at(i), positions_of_treasure.at(i + 1));
            }
            dist += APSP_Floyd_Warshall::dist(positions_of_treasure.back(), n);
            min_dist = min(min_dist, dist);
        } while (next_permutation(positions_of_treasure.begin(), positions_of_treasure.end()));
        IO::writeln(min_dist);
    }

    return 0;
}
