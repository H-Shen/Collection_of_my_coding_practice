// https://open.kattis.com/problems/visualgo
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    vector<ll> num;    // num.at(n) = the number of shortest path from source to n
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
        num.resize(number_of_nodes + 5);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
        decltype(pq)().swap(pq);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        num.at(source) = 1;
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
                    num.at(to) = num.at(v);
                    pq.push(make_pair(dis.at(to), to));
                } else if (dis.at(to) == dis.at(v) + weight) {
                    num.at(to) += num.at(v);
                }
            }
        }
    }
}

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

int main() {

    int n, m, u, v, w, s, t;
    IO::read(n, m);
    SSSP_Dijkstra_1::init(n);
    while (m--) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
    }
    IO::read(s, t);
    SSSP_Dijkstra_1::source = s;
    SSSP_Dijkstra_1::dijkstra();
    if (SSSP_Dijkstra_1::dis.at(t) == SSSP_Dijkstra_1::INF) {
        IO::writeln(0);
    } else {
        IO::writeln(SSSP_Dijkstra_1::num.at(t));
    }

    return 0;
}
