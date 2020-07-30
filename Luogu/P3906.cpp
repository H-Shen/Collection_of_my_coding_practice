#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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
        adj_matrix.resize(number_of_nodes, vector<int>(number_of_nodes, INF));
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
                        adj_matrix.at(k).at(j) < INF &&
                        adj_matrix.at(i).at(j) > adj_matrix.at(i).at(k) +
                                                 adj_matrix.at(k).at(j)) {
                        adj_matrix.at(i).at(j) =
                                adj_matrix.at(i).at(k) +
                                adj_matrix.at(k).at(j);
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

    inline
    vector<int> get_vertices(const int &u, const int &v) {
        vector<int> result;
        result.emplace_back(u);
        for (int i = 0; i < number_of_nodes; ++i) {
            if (i != u && i != v && adj_matrix.at(u).at(i) + adj_matrix.at(i).at(v) == adj_matrix.at(u).at(v)) {
                result.emplace_back(i);
            }
        }
        result.emplace_back(v);
        sort(result.begin(), result.end());
        return result;
    }
}


int main() {

    int n, m, u, v, k;
    IO::read(n, m);
    APSP_Floyd_Warshall::init(n);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v);
        --u;
        --v;
        APSP_Floyd_Warshall::adj_matrix.at(u).at(v) = 1;
        APSP_Floyd_Warshall::adj_matrix.at(v).at(u) = 1;
    }
    APSP_Floyd_Warshall::floyd_warshall();
    IO::read(k);
    vector<int> output;
    for (int i = 0; i < k; ++i) {
        IO::read(u, v);
        --u;
        --v;
        output = APSP_Floyd_Warshall::get_vertices(u, v);
        for (const auto &j : output) {
            IO::write(j + 1);
            putchar_unlocked(' ');
        }
        putchar_unlocked('\n');
    }
    return 0;
}