// When we calculate the shortest path by multiplication of weights of all edges,
// we can convert it from min(a*b*c*d*...) -> min(log a + log b + log c + ...)
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 9987;

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

constexpr double EPS = 1e-7;
inline
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

namespace SSSP_Dijkstra_1 {

    constexpr double INF = 1e9; //  A weight indicates two nodes have no paths between them
    gp_hash_table<int, gp_hash_table<int, int, custom_hash>, custom_hash> adj;
    int number_of_nodes;

    vector<double> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    vector<int> prev;   // an auxiliary container to store the path
    std::priority_queue<pair<double, int>, vector<pair<double, int> >, greater<> > pq;

    inline void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
        dis.resize(number_of_nodes + 5, INF);
        if (store_path) {
            prev.resize(number_of_nodes + 5, -1);
        }
    }

    inline void
    add_edge(int u, int v, int w) {
        auto iter = adj[u].find(v);
        if (iter != adj[u].end()) {
            iter->second = min(w, iter->second);
        } else {
            adj[u][v] = w;
        }
    }

    inline void
    dijkstra(bool store_path = false) {
        dis.at(source) = 0.0;
        pq.push(make_pair(0.0, source));
        while (!pq.empty()) {
            double d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (sgn(d_v - dis.at(v)) != 0) {
                continue;
            }
            for (const auto &[to, weight] : adj[v]) {
                if (sgn(dis.at(to) - dis.at(v) - log2(weight)) > 0) {
                    dis.at(to) = dis.at(v) + log2(weight);
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

    int n, m, x, y, z;
    IO::read(n, m);
    SSSP_Dijkstra_1::init(n, true);
    SSSP_Dijkstra_1::source = 1;
    for (int i = 0; i < m; ++i) {
        IO::read(x, y, z);
        SSSP_Dijkstra_1::add_edge(x, y, z);
    }
    SSSP_Dijkstra_1::dijkstra(true);
    auto path = SSSP_Dijkstra_1::get_path(n);
    if (path.size() == 1) {
        IO::writeln(0);
    } else {
        ll sum = 1;
        ll weight;
        int length = static_cast<int>(path.size());
        for (int i = 1; i < length; ++i) {
            weight = SSSP_Dijkstra_1::adj[path.at(i - 1)][path.at(i)];
            sum = (sum * weight) % MOD;
        }
        IO::writeln(sum);
    }

    return 0;
}
