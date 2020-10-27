// Shortest path with maximal summation of weights of nodes
//
// https://open.kattis.com/problems/bigtruck
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    vector<int> weights; // weight.at(i) = the weight in the node i
    vector<int> W;      // W.at(u) = the maximal weight you can take from 'source' to 'u'
    int source;         // the node id of the source
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
        weights.resize(number_of_nodes + 5);
        W.resize(number_of_nodes + 5);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        W.at(source) = weights.at(source);
        pq.push(make_pair(dis.at(source), source));
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
                    W.at(to) = W.at(v) + weights.at(to);
                    pq.push(make_pair(dis.at(to), to));
                } else if (dis.at(to) == dis.at(v) + weight) {
                    if (W.at(to) < W.at(v) + weights.at(to)) {
                        W.at(to) = W.at(v) + weights.at(to);
                    }
                }
            }
        }
    }
}

int main() {

    int n, u, v, w;
    IO::read(n);
    SSSP_Dijkstra_1::init(n);
    for (int i = 1; i <= n; ++i) {
        IO::read(SSSP_Dijkstra_1::weights.at(i));
    }
    int m;
    IO::read(m);
    while (m--) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
        SSSP_Dijkstra_1::add_edge(v, u, w);
    }
    SSSP_Dijkstra_1::source = 1;
    SSSP_Dijkstra_1::dijkstra();
    if (SSSP_Dijkstra_1::dis.at(n) == SSSP_Dijkstra_1::INF) {
        puts("impossible");
    } else {
        IO::write(SSSP_Dijkstra_1::dis.at(n));
        putchar_unlocked(' ');
        IO::writeln(SSSP_Dijkstra_1::W.at(n));
    }

    return 0;
}
