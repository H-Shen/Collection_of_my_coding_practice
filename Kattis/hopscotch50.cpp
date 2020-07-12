// https://open.kattis.com/problems/hopscotch50
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 50 + 5;

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

// The implementation of Dijkstra using adjacency list
namespace SSSP1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    vector<int> prev;   // an auxiliary container to store the path
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
        if (store_path) {
            prev.resize(number_of_nodes, -1);
        }
    }

    inline void
    reset(bool store_path = false) {
        fill(dis.begin(), dis.end(), INF);
        pq = decltype(pq)();
        if (store_path) {
            fill(prev.begin(), prev.end(), -1);
        }
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline void
    dijkstra(bool store_path = false) {
        dis.at(source) = 0;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : adj.at(v)) {
                if (dis.at(to) > dis.at(v) + weight) {
                    dis.at(to) = dis.at(v) + weight;
                    if (store_path) {
                        prev.at(to) = v;
                    }
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }

    inline vector<int>
    get_path(int destination) {
        vector<int> path;
        for (; destination != -1; destination = prev.at(destination)) {
            path.emplace_back(destination);
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

int n, k, val;
vector<vector<pair<int, int> > > G;
int minimal_dist = numeric_limits<int>::max();

int main(int argc, char *argv[]) {

    IO::read(n, k);
    G.resize(k + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            IO::read(val);
            G.at(val).emplace_back(make_pair(i, j));
        }
    }
    // Case 1: missing some number from 1 to k
    for (int i = 1; i <= k; ++i) {
        if (G.at(i).empty()) {
            IO::writeln(-1);
            return 0;
        }
    }
    // Case 2:
    SSSP1::init(n * n);
    // add edges from 2 to k
    for (int i = 1; i <= k - 1; ++i) {
        // G.at(i) -> G.at(i + 1)
        for (const auto &u : G.at(i)) {
            for (const auto &v : G.at(i + 1)) {
                SSSP1::add_edge(u.first * n + u.second, v.first * n + v.second,
                                abs(u.first - v.first) + abs(u.second - v.second));
            }
        }
    }
    for (const auto &u : G.at(1)) {
        SSSP1::source = u.first * n + u.second;
        SSSP1::dijkstra();
        for (const auto &v : G.at(k)) {
            minimal_dist = min(minimal_dist, SSSP1::dis.at(v.first * n + v.second));
        }
        SSSP1::reset();
    }
    IO::writeln(minimal_dist);
    return 0;
}
