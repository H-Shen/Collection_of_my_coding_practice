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

namespace MinimumWeightCycle {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > adj_matrix;
    int number_of_nodes;
    void init(int n) {
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes + 5, vector<int>(number_of_nodes + 5, INF));
        for (int i = 1; i <= number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0;
        }
    }
    void add_edge(int u, int v, int w) {
        adj_matrix.at(u).at(v) = w;
        adj_matrix.at(v).at(u) = w;
    }
    // Obtain the summation of weights in the minimum weight cycle,
    // return false if no such cycle exists
    bool floyd(ll &answer) {
        vector<vector<int> > dis(adj_matrix);
        answer = INF;
        for (int k = 1; k <= number_of_nodes; ++k) {
            for (int i = 1; i < k; ++i) {
                for (int j = 1; j < i; ++j) {
                    answer = min(answer, dis.at(i).at(j) * 1LL + adj_matrix.at(i).at(k) + adj_matrix.at(k).at(j));
                }
            }
            for (int i = 1; i <= number_of_nodes; ++i) {
                for (int j = 1; j <= number_of_nodes; ++j) {
                    dis.at(i).at(j) = min(dis.at(i).at(j), dis.at(i).at(k) + dis.at(k).at(j));
                }
            }
        }
        return answer < INF;
    }
}

int main() {

    int n, m, u, v, d;
    IO::read(n, m);
    MinimumWeightCycle::init(n);
    while (m--) {
        IO::read(u, v, d);
        MinimumWeightCycle::add_edge(u, v, d);
    }
    ll answer;
    if (MinimumWeightCycle::floyd(answer)) {
        IO::writeln(answer);
    } else {
        fputs_unlocked("No solution.\n", stdout);
    }

    return 0;
}