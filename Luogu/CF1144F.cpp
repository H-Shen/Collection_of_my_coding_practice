#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

// Check whether an undirected graph is bipartite
// Principle: a graph is bipartite if and only if it is two-colorable (0/1)
namespace BipartiteCheck {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > adj;
    vector<int> color;
    int n;
    void init(int number_of_nodes) {
        n = number_of_nodes;
        vector<int>().swap(color);
        color.resize(n, INF);
    }
    bool bfs() {
        bool result = true;
        // bfs from every node id, which will cover different CCs
        queue<int> q;
        for (int s = 0; s < n; ++s) {
            if (color.at(s) == INF) {
                color.at(s) = 0;
                q.push(s);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const auto &v : adj.at(u)) {
                    if (color.at(v) == INF) {
                        // if color[u] = 1, then color[v] = 0
                        // if color[u] = 0, then color[v] = 1
                        color.at(v) = 1 - color.at(u);
                        q.push(v);
                    } else if (color.at(v) == color.at(u)) {
                        // Coloring conflict found, exit
                        result = false;
                        return result;
                    }
                }
            }
        }
        return result;
    }
}

int main() {

    int n, m, u, v;
    IO::read(n, m);
    BipartiteCheck::init(n);
    vector<pii> edges(m);
    BipartiteCheck::adj.resize(n);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v);
        --u;
        --v;
        edges.at(i) = {u, v};
        BipartiteCheck::adj.at(u).emplace_back(v);
        BipartiteCheck::adj.at(v).emplace_back(u);
    }
    if (BipartiteCheck::bfs()) {
        printf("YES\n");
        for (const auto &i : edges) {
            if (BipartiteCheck::color.at(i.first) == 0 && BipartiteCheck::color.at(i.second) == 1) {
                putchar('1');
            } else {
                putchar('0');
            }
        }
        putchar('\n');
    } else {
        printf("NO\n");
    }

    return 0;
}
