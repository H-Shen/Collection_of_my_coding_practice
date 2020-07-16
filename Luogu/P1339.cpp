#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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
    gp_hash_table<int, gp_hash_table<int, int, custom_hash>, custom_hash > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    vector<int> prev;   // an auxiliary container to store the path
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
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
        if (adj[u].find(v) == adj[u].end()) {
            adj[u][v] = w;
        } else {
            adj[u][v] = min(adj[u][v], w);
        }
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
            for (const auto &[to, weight] : adj[v]) {
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

int main() {

    int n, m, s, t, u, v, w;
    IO::read(n, m, s, t);
    SSSP1::init(n);
    SSSP1::source = s;
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        SSSP1::add_edge(u, v, w);
        SSSP1::add_edge(v, u, w);
    }
    SSSP1::dijkstra();
    IO::writeln(SSSP1::dis.at(t));

    return 0;
}
