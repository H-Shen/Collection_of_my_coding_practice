// If we want to query the shortest distance in a directed graph to the same destination,
// we can reverse all edges, change the destination to the source and run Dijkstra on the
// new graph, the then dis.at(a) = the shortest distance from 1 to a in the original graph.
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

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    vector<vector<pair<int, int> > > adj_rev;
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        adj_rev.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
        decltype(pq)().swap(pq);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
        adj_rev.at(v).emplace_back(make_pair(u, w));
    }

    inline void
    dijkstra(const vector<vector<pair<int, int> > > &G) {
        dis.at(source) = 0;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : G.at(v)) {
                if (dis.at(to) > dis.at(v) + weight) {
                    dis.at(to) = dis.at(v) + weight;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
}

int main() {

    int n, m, u, v, w;
    IO::read(n, m);
    SSSP_Dijkstra_1::source = 1;
    SSSP_Dijkstra_1::init(n);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
    }
    ll sum = 0;
    // sum the shortest distance of (1,2),(1,3),...,(1,n)
    SSSP_Dijkstra_1::dijkstra(SSSP_Dijkstra_1::adj);
    for (int i = 2; i <= n; ++i) {
        sum += SSSP_Dijkstra_1::dis.at(i);
    }
    SSSP_Dijkstra_1::reset();
    SSSP_Dijkstra_1::dijkstra(SSSP_Dijkstra_1::adj_rev);
    for (int i = 2; i <= n; ++i) {
        sum += SSSP_Dijkstra_1::dis.at(i);
    }
    IO::writeln(sum);

    return 0;
}
