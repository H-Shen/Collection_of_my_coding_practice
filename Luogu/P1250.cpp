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

namespace SSSP_SPFA {

    constexpr int MAX_NODES = 30005;
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    init(int n, int s) {
        vector<vector<pair<int, int> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, -INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    bitset<MAX_NODES> in_queue;
    inline bool
    spfa() {
        vector<int> cnt(number_of_nodes + 5);
        queue<int> q;
        q.push(source);
        in_queue[source] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (const auto &[v, w] : adj.at(u)) {
                if (dis.at(v) < dis.at(u) + w) {
                    dis.at(v) = dis.at(u) + w;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                        ++cnt.at(v);
                        if (cnt.at(v) > number_of_nodes) {
                            return false;   // a negative cycle exists
                        }
                    }
                }
            }
        }
        return true;
    }
}

int main() {

    int n, h, b, e, t;
    IO::read(n, h);
    SSSP_SPFA::init(n, 0);
    for (int i = 0; i < h; ++i) {
        IO::read(b, e, t);
        if (b == 1) {
            // sum[e] >= t -> y[e] - x >= t
            SSSP_SPFA::add_edge(n + 1, e, t);
        } else {
            // sum[e] - sum[b - 1] >= t -> y[e] - y[b - 1] >= t
            SSSP_SPFA::add_edge(b - 1, e, t);
        }
    }
    // sum[i + 1] - sum[i] >= 0 && sum[i + 1] - sum[i] <= 1
    // -> y[i + 1] - y[i] >= 0 && y[i] - y[i + 1] >= -1
    for (int i = 1; i <= n - 1; ++i) {
        SSSP_SPFA::add_edge(i, i + 1, 0);
        SSSP_SPFA::add_edge(i + 1, i, -1);
    }
    // sum[1] >= 0 && sum[1] <= 1
    // -> y[1] - x >= 0 && y[1] - x <= 1
    // -> y[1] - x >= 0 && x - y[1] >= -1
    SSSP_SPFA::add_edge(n + 1, 1, 0);
    SSSP_SPFA::add_edge(1, n + 1, -1);
    // Add edges from the node 0 to other nodes
    for (int i = 1; i <= n + 1; ++i) {
        SSSP_SPFA::add_edge(0, i, 0);
    }
    SSSP_SPFA::spfa();
    IO::writeln(SSSP_SPFA::dis.at(n));

    return 0;
}