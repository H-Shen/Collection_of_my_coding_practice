#include <bits/extc++.h>

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

vector<int> dist;
vector<int> parent;
void dfs(int u, int depth) {
    dist[u] = depth;
    for (const auto &v : LCA2::adj[u]) {
        if (dist[v] == -1) {
            dfs(v, depth + 1);
        }
    }
}

int main() {

    int n, m, a, b, c;
    IO::read(n, m);
    dist.resize(n, -1);
    parent.resize(n, -1);
    LCA2::preprocess(n);
    for (int i = 0; i < n - 1; ++i) {
        IO::read(a, b);
        --a;
        --b;
        parent[b] = a;
        LCA2::adj[a].emplace_back(b);
        LCA2::adj[b].emplace_back(a);
    }
    // get root
    int root = 0;
    while (parent[root] != -1) {
        root = parent[root];
    }
    LCA2::init(root);
    dfs(root, 0);
    int lca_ab, lca_ac, lca_bc, cost, destination;
    while (m--) {
        IO::read(a, b, c);
        --a;
        --b;
        --c;
        lca_ab = LCA2::lca(a, b);
        lca_ac = LCA2::lca(a, c);
        lca_bc = LCA2::lca(b, c);
        if (lca_ab == lca_ac && lca_ac == lca_bc) {
            destination = lca_ac;
            cost = dist[a] + dist[b] + dist[c] - 3 * dist[lca_ab];
        }
        else if (lca_ab == lca_ac) {
            destination = lca_bc;
            cost = dist[b] + dist[a] - 2 * dist[lca_ab] + dist[c] - dist[lca_bc];
        }
        else if (lca_ac == lca_bc) {
            destination = lca_ab;
            cost = dist[b] + dist[c] - 2 * dist[lca_bc] + dist[a] - dist[lca_ab];
        }
        else if (lca_ab == lca_bc) {
            destination = lca_ac;
            cost = dist[b] + dist[c] - 2 * dist[lca_bc] + dist[a] - dist[lca_ac];
        }
        IO::write(destination + 1);
        putchar(' ');
        IO::writeln(cost);
    }

    return 0;
}