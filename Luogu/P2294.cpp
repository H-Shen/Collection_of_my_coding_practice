#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int MAXN = 110;

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

// If you want to query the longest path from a single source
// change INF to -INF and change the condition of relaxing from < to >
namespace SSSP_SPFA {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;
    vector<int> dis;
    inline void
    reset() {
        decltype(adj)().swap(adj);
        vector<int>().swap(dis);
        number_of_nodes = 0;
    }
    inline void
    init(int n) {
        number_of_nodes = n;
        adj.resize(number_of_nodes + 5);
    }
    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }
    inline bool
    spfa(int source) {
        decltype(dis)().swap(dis);
        dis.resize(number_of_nodes + 5, INF);
        dis.at(source) = 0;
        vector<int> cnt(number_of_nodes + 5);
        bitset<MAXN> in_queue;
        queue<int> q;
        q.push(source);
        in_queue[source] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (const auto &[v, w] : adj.at(u)) {
                if (dis.at(u) + w < dis.at(v)) {
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

    int kase, n, m, s, t, v;
    IO::read(kase);
    while (kase--) {
        IO::read(n, m);
        SSSP_SPFA::init(n);
        while (m--) {
            IO::read(s, t, v);
            if (s == 1) {
                SSSP_SPFA::add_edge(t, n + 1, -v);
                SSSP_SPFA::add_edge(n + 1, t, v);
            } else {
                SSSP_SPFA::add_edge(t, s - 1, -v);
                SSSP_SPFA::add_edge(s - 1, t, v);
            }
        }
        for (int i = 1; i <= n + 1; ++i) {
            SSSP_SPFA::add_edge(0, i, 0);
        }
        cout << boolalpha << SSSP_SPFA::spfa(0) << '\n';
        SSSP_SPFA::reset();
    }
    return 0;
}