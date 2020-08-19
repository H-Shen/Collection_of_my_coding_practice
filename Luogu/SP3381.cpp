#include <bits/stdc++.h>

using namespace std;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source

    inline void
    init(int n) {
        number_of_nodes = n;
        // clean the containers
        decltype(adj)().swap(adj);
        decltype(dis)().swap(dis);
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
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
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
}

int main() {

    int t, n, m, s, d, u, v, w;
    IO::read(t);
    while (t--) {
        IO::read(n, m, s, d);
        SSSP_Dijkstra_1::init(n);
        while (m--) {
            IO::read(u, v, w);
            SSSP_Dijkstra_1::add_edge(u, v, w);
            SSSP_Dijkstra_1::add_edge(v, u, w);
        }
        SSSP_Dijkstra_1::source = s;
        SSSP_Dijkstra_1::dijkstra();
        if (SSSP_Dijkstra_1::dis.at(d) == SSSP_Dijkstra_1::INF) {
            fputs("NONE\n", stdout);
        } else {
            IO::writeln(SSSP_Dijkstra_1::dis.at(d));
        }
        SSSP_Dijkstra_1::reset();
    }

    return 0;
}
