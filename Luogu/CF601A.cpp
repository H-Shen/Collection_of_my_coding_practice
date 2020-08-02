#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define CODEFORCES

#ifdef CODEFORCES
namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = _getchar_nolock(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = _getchar_nolock();
        while (isdigit(c)) t = t * 10 + c - 48, c = _getchar_nolock();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, _putchar_nolock('-');
        if (x > 9) write(x / 10);
        _putchar_nolock(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        _putchar_nolock('\n');
    }
}
#else
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
#endif

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

namespace SSSP_Dijkstra_Railway {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        dis.resize(number_of_nodes + 5, INF);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
        decltype(pq)().swap(pq);
    }

    inline void
    add_edge(int u, int v) {
        adj[u].insert(v);
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &to : adj[v]) {
                if (dis.at(to) > dis.at(v) + 1) {
                    dis.at(to) = dis.at(v) + 1;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
}

namespace SSSP_Dijkstra_way {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        dis.resize(number_of_nodes + 5, INF);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
        decltype(pq)().swap(pq);
    }

    inline void
    add_edge(int u, int v) {
        adj[u].insert(v);
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &to : adj[v]) {
                if (dis.at(to) > dis.at(v) + 1) {
                    dis.at(to) = dis.at(v) + 1;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
}

int main() {

    int n, m, u, v;
    IO::read(n, m);
    SSSP_Dijkstra_Railway::init(n);
    SSSP_Dijkstra_way::init(n);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v);
        SSSP_Dijkstra_Railway::add_edge(u, v);
        SSSP_Dijkstra_Railway::add_edge(v, u);
    }
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (SSSP_Dijkstra_Railway::adj.find(i) ==
                SSSP_Dijkstra_Railway::adj.end() ||
                SSSP_Dijkstra_Railway::adj[i].find(j) ==
                SSSP_Dijkstra_Railway::adj[i].end()) {
                SSSP_Dijkstra_way::add_edge(i, j);
                SSSP_Dijkstra_way::add_edge(j, i);
            }
        }
    }
    SSSP_Dijkstra_Railway::source = 1;
    SSSP_Dijkstra_Railway::dijkstra();
    if (SSSP_Dijkstra_Railway::dis.at(n) == SSSP_Dijkstra_Railway::INF) {
        IO::writeln(-1);
        return 0;
    }
    SSSP_Dijkstra_way::source = 1;
    SSSP_Dijkstra_way::dijkstra();
    if (SSSP_Dijkstra_way::dis.at(n) == SSSP_Dijkstra_way::INF) {
        IO::writeln(-1);
        return 0;
    }
    IO::writeln(max(SSSP_Dijkstra_way::dis.at(n), SSSP_Dijkstra_Railway::dis.at(n)));


    return 0;
}