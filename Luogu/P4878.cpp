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
    constexpr int MAX_NODES = 1005;
    constexpr ll INF = 0x3f3f3f3f3f;
    vector<vector<pair<int, ll> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<ll> dis;

    inline void
    init(int n, int s) {
        vector<vector<pair<int, ll> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, ll w) {
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
                if (dis.at(v) > dis.at(u) + w) {
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

    int n, m_l, m_d, x_a, x_b;
    ll d;
    IO::read(n, m_l, m_d);
    SSSP_SPFA::init(n, 0);
    // x_b - x_a <= d
    for (int i = 0; i < m_l; ++i) {
        IO::read(x_a, x_b, d);
        SSSP_SPFA::add_edge(x_a, x_b, d);
    }
    // x_b - x_a >= d
    for (int i = 0; i < m_d; ++i) {
        IO::read(x_a, x_b, d);
        SSSP_SPFA::add_edge(x_b, x_a, -d);
    }
    // x_(i+1) - x_i >= 0 -> x_i - x_(i+1) <= 0
    for (int i = 1; i <= n - 1; ++i) {
        SSSP_SPFA::add_edge(i + 1, i, 0);
    }
    for (int i = 1; i <= n; ++i) {
        SSSP_SPFA::add_edge(0, i, 0);
    }
    if (!SSSP_SPFA::spfa()) {
        IO::writeln(-1);
        return 0;
    }
    // reset and run spfa from 1
    fill(SSSP_SPFA::dis.begin(), SSSP_SPFA::dis.end(), SSSP_SPFA::INF);
    SSSP_SPFA::source = 1;
    SSSP_SPFA::dis.at(SSSP_SPFA::source) = 0;
    SSSP_SPFA::in_queue.reset();
    SSSP_SPFA::spfa();
    if (SSSP_SPFA::dis.at(n) == SSSP_SPFA::INF) {
        IO::writeln(-2);
    } else {
        IO::writeln(SSSP_SPFA::dis.at(n));
    }
    return 0;
}