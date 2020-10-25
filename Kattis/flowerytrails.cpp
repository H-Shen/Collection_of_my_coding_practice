// https://open.kattis.com/problems/flowerytrails
//
// How to check if an edge E is on the shortest path from u to v
// 1. Get dis1.at(i) = the shortest path from u to i by Dij
// 2. Get dis2.at(i) = the shortest path from v to i by Dij
// 3. For each edge E:(a, b) -> w, if
// dis1.at(a) + w + dis2.at(b) = shortest path from u to v
// OR
// dis2.at(a) + w + dis1.at(b) = shortest path from u to v
// the E:(a, b) -> w is on the shortest path from u to v

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
    }


    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline vector<int>
    dijkstra(int source) {
        vector<int> dis(number_of_nodes + 5, INF);
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
        return dis;
    }
}

struct Edge {
    explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    int u, v, w;
};

int p, t, u, v, w;
vector<Edge> edges;

int main() {

    IO::read(p, t);
    SSSP_Dijkstra_1::init(p);
    for (int i = 0; i < t; ++i) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
        SSSP_Dijkstra_1::add_edge(v, u, w);
        edges.emplace_back(Edge(u, v, w));
    }
    auto dis1 = SSSP_Dijkstra_1::dijkstra(0);
    auto dis2 = SSSP_Dijkstra_1::dijkstra(p - 1);
    // sum the distance from every edge E such that E is in the shortest path
    ll sum = 0;
    for (const auto &e : edges) {
        if (dis1.at(e.u) + e.w + dis2.at(e.v) == dis1.at(p - 1) ||
            dis1.at(e.v) + e.w + dis2.at(e.u) == dis1.at(p - 1)) {
            sum += e.w;
        }
    }
    IO::writeln(sum << 1);

    return 0;
}
