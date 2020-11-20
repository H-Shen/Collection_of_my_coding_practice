#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
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
        color.resize(n + 5, INF);
    }
    bool bfs(int s, unordered_map<int, unordered_set<int, custom_hash>, custom_hash > adj) {
        bool isBipartite = true;
        queue<int> q;
        color.at(s) = 0;
        q.push(s);
        while (!q.empty() && isBipartite) {
            int u = q.front();
            q.pop();
            for (const auto &v : adj[u]) {
                if (color.at(v) == INF) {
                    // if color[u] = 1, then color[v] = 0
                    // if color[u] = 0, then color[v] = 1
                    color.at(v) = 1 - color.at(u);
                    q.push(v);
                } else if (color.at(v) == color.at(u)) {
                    // Coloring conflict found
                    isBipartite = false;
                    break;
                }
            }
        }
        return isBipartite;
    }
}

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

int main() {

    int t, n, m, v;
    IO::read(t);
    while (t--) {
        IO::read(n);
        DSU::init(n);
        BipartiteCheck::init(n);
        unordered_map<int, unordered_set<int, custom_hash>, custom_hash > adj;
        for (int i = 1; i <= n; ++i) {
            IO::read(m);
            for (int j = 0; j < m; ++j) {
                IO::read(v);
                // The enemy's number can be out of invitation
                if (v > n) {
                    continue;
                }
                adj[i].insert(v);
                adj[v].insert(i);
                DSU::merge(i, v);
            }
        }
        unordered_map<int, vector<int>, custom_hash> groups;
        for (int i = 1; i <= n; ++i) {
            groups[DSU::find(i)].emplace_back(i);
        }
        int counter = 0;
        for (const auto &i : groups) {
            if (BipartiteCheck::bfs(i.first, adj)) {
                int left = 0;
                int right = 0;
                for (const auto &j : i.second) {
                    if (BipartiteCheck::color.at(j) == 1) {
                        ++left;
                    } else {
                        ++right;
                    }
                }
                counter += max(left, right);
            }
        }
        IO::writeln(counter);
    }

    return 0;
}
