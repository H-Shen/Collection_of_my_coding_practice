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

    constexpr ll INF = 0x3f3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<gp_hash_table<int, ll, custom_hash> > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<ll> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    std::priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
        decltype(pq)().swap(pq);
    }

    inline void
    add_edge(int u, int v, ll w) {
        adj[u][v] = w;
    }

    inline void
    update_edge(int u, int v) {
        adj[u][v] <<= 1;
        adj[v][u] <<= 1;
    }

    inline void
    restore_edge(int u, int v) {
        adj[u][v] >>= 1;
        adj[v][u] >>= 1;
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            ll d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : adj[v]) {
                if (dis.at(to) > dis.at(v) + weight) {
                    dis.at(to) = dis.at(v) + weight;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
}

vector<pair<int, int> > edges;

int main() {

    int n, m, u, v;
    ll w;
    IO::read(n, m);
    SSSP_Dijkstra_1::init(n);
    SSSP_Dijkstra_1::source = 1;
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        edges.emplace_back(make_pair(u, v));
        SSSP_Dijkstra_1::add_edge(u, v, w);
        SSSP_Dijkstra_1::add_edge(v, u, w);
    }
    SSSP_Dijkstra_1::dijkstra();
    ll original_shortest_dist = SSSP_Dijkstra_1::dis.at(n);
    ll max_inc = numeric_limits<ll>::min();
    for (const auto &i : edges) {
        SSSP_Dijkstra_1::reset();
        SSSP_Dijkstra_1::update_edge(i.first, i.second);
        SSSP_Dijkstra_1::dijkstra();
        max_inc = max(max_inc, SSSP_Dijkstra_1::dis.at(n) - original_shortest_dist);
        SSSP_Dijkstra_1::restore_edge(i.first, i.second);
    }
    IO::writeln(max_inc);
    return 0;
}