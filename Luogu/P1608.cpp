#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 2005;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(const uint64_t &x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    array<gp_hash_table<int, int, custom_hash>, MAXN> adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    vector<ll> num;    // num.at(n) = the number of shortest path from source to n
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
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
        auto iter = adj.at(u).find(v);
        if (iter == adj.at(u).end()) {
            adj.at(u)[v] = w;
        } else {
            iter->second = min(iter->second, w);
        }
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

    int n, m, u, v, w;
    IO::read(n, m);
    SSSP_Dijkstra_1::init(n);
    while (m--) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
    }
    int s = 1;
    int t = n;
    SSSP_Dijkstra_1::source = s;
    SSSP_Dijkstra_1::dijkstra();
    if (SSSP_Dijkstra_1::dis.at(t) == SSSP_Dijkstra_1::INF) {
        fputs_unlocked("No answer\n", stdout);
    } else {
        IO::write(SSSP_Dijkstra_1::dis.at(t));
        putchar_unlocked(' ');
        IO::writeln(SSSP_Dijkstra_1::num.at(t));
    }

    return 0;
}
