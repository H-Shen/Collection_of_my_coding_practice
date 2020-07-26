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

    constexpr ll LINF = 0x3f3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, ll> > > adj; // The adjacency list of the graph
    vector<vector<pair<int, ll> > > adj_rev;
    int number_of_nodes;

    vector<ll> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    std::priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        adj_rev.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, LINF);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), LINF);
        decltype(pq)().swap(pq);
    }

    inline void
    add_edge(int u, int v, ll w) {
        adj.at(u).emplace_back(make_pair(v, w));
        adj_rev.at(v).emplace_back(make_pair(u, w));
    }

    inline void
    dijkstra(const vector<vector<pair<int, ll> > > &G) {
        dis.at(source) = 0;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            ll d_v = pq.top().first;
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

    int n, m, u, v;
    ll w;
    IO::read(n, m);
    SSSP_Dijkstra_1::init(n);
    SSSP_Dijkstra_1::source = 1;
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
    }
    ll sum = 0;
    SSSP_Dijkstra_1::dijkstra(SSSP_Dijkstra_1::adj);
    sum += accumulate(SSSP_Dijkstra_1::dis.begin() + 1, SSSP_Dijkstra_1::dis.begin() + n + 1, 0LL);
    SSSP_Dijkstra_1::reset();
    SSSP_Dijkstra_1::dijkstra(SSSP_Dijkstra_1::adj_rev);
    sum += accumulate(SSSP_Dijkstra_1::dis.begin() + 1, SSSP_Dijkstra_1::dis.begin() + n + 1, 0LL);
    IO::writeln(sum);
    return 0;
}