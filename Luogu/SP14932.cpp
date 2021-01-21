#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

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

// Least Common Ancestor, implemented with binary lifting
namespace LCA2 {

    int n, l;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    // O(logn)
    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    void reset() {
        decltype(tin)().swap(tin);
        decltype(tout)().swap(tout);
        decltype(adj)().swap(adj);
        decltype(up)().swap(up);
    }

    // O(nlogn)
    void preprocess(int number_of_nodes) {
        n = number_of_nodes;
        tin.resize(n);
        tout.resize(n);
        adj.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.resize(n, vector<int>(l + 1));
    }

    void init(int root) {
        dfs(root, root);
    }
}

int main() {

    int t;
    IO::read(t);
    int n, u, v, m, root, q;
    for (int kase = 1; kase <= t; ++kase) {
        IO::read(n);
        vector<int> parent(n, -1);
        LCA2::preprocess(n);
        for (int i = 1; i <= n; ++i) {
            u = i;
            --u;
            IO::read(m);
            while (m--) {
                IO::read(v);
                --v;
                LCA2::adj[u].emplace_back(v);
                LCA2::adj[v].emplace_back(u);
                parent[v] = u;
            }
        }
        // get root
        root = 5;
        while (parent[root] != -1) {
            root = parent[root];
        }
        LCA2::init(root);
        IO::read(q);
        printf("Case %d:\n", kase);
        while (q--) {
            IO::read(u, v);
            --u;
            --v;
            IO::writeln(LCA2::lca(u, v) + 1);
        }
        // reset
        LCA2::reset();
    }

    return 0;
}