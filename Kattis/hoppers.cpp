// https://open.kattis.com/problems/hoppers

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
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

namespace DSU {
    vector<int> father, Size;
    int number_of_sets;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        number_of_sets = n;
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
        --number_of_sets;
    }
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
    int check_set_size(int x) {
        return Size[find(x)];
    }
    int number_of_disjoint_sets() {
        return number_of_sets;
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
        color.resize(n + 5, INF);
        adj.resize(n + 5);
    }
    // bfs from every node id, which will cover different CCs
    bool bfs() {
        queue<int> q;
        for (int s = 1; s <= n; ++s) {
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
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

int main() {

    int n, m, u, v;
    IO::read(n, m);
    DSU::init(n);
    BipartiteCheck::init(n);
    while (m--) {
        IO::read(u, v);
        DSU::merge(u, v);
        BipartiteCheck::adj.at(u).emplace_back(v);
        BipartiteCheck::adj.at(v).emplace_back(u);
    }
    if (BipartiteCheck::bfs()) {
        IO::writeln(DSU::number_of_disjoint_sets());
    } else {
        IO::writeln(DSU::number_of_disjoint_sets() - 1);
    }
    return 0;
}

