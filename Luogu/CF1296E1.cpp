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
    vector<int> color;
    int n;
    void init(int number_of_nodes) {
        n = number_of_nodes;
        vector<int>().swap(color);
        color.resize(n, INF);
    }
    bool bfs(unordered_map<int, unordered_set<int> > adj) {
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
                for (const auto &v : adj[u]) {
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

auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main() {

    fast_io();
    int n, u, v;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<int, unordered_set<int> > adj;
    vector<pair<char, int> > vec(s.size());
    for (int i = 0; i < n; ++i) {
        vec.at(i) = {s.at(i), i};
    }
    // bubblesort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (vec.at(j).first > vec.at(j + 1).first) {
                u = vec.at(j).second;
                v = vec.at(j + 1).second;
                if (u > v) {
                    swap(u, v);
                }
                adj[u].insert(v);
                adj[v].insert(u);
                swap(vec.at(j), vec.at(j + 1));
            }
        }
    }
    BipartiteCheck::init(n);
    if (BipartiteCheck::bfs(adj)) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            cout << BipartiteCheck::color.at(i);
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
