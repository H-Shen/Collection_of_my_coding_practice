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
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    // O(mn)
    inline bool
    spfa() {
        vector<int> cnt(number_of_nodes + 5);
        vector<bool> in_queue(number_of_nodes + 5, false);
        queue<int> q;
        q.push(source);
        in_queue.at(source) = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue.at(u) = false;
            for (const auto &[v, w] : adj.at(u)) {
                if (dis.at(v) > dis.at(u) + w) {
                    dis.at(v) = dis.at(u) + w;
                    if (!in_queue.at(v)) {
                        q.push(v);
                        in_queue.at(v) = true;
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

    int n, m, type, a, b, c;
    IO::read(n, m);
    SSSP_SPFA::init(n + 1, 0);
    while (m--) {
        IO::read(type);
        switch (type) {
            case 1:
                // x_a - x_b >= c, which is x_b - x_a <= -c
                IO::read(a, b, c);
                SSSP_SPFA::add_edge(a, b, -c);
                break;
            case 2:
                // x_a - x_b <= c
                IO::read(a, b, c);
                SSSP_SPFA::add_edge(b, a, c);
                break;
            default:
                // x_a = x_b, which is x_b - x_a <= 0 and x_a - x_b <= 0
                IO::read(a, b);
                SSSP_SPFA::add_edge(a, b, 0);
                SSSP_SPFA::add_edge(b, a, 0);
                break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        SSSP_SPFA::add_edge(0, i, 0);
    }
    if (SSSP_SPFA::spfa()) {
        fputs_unlocked("Yes\n", stdout);
    } else {
        fputs_unlocked("No\n", stdout);
    }
    return 0;
}