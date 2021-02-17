// // https://loj.ac/problem/10130
// Unlike lcaExample1.cpp, this solution uses binary lifting to obtain LCA and use prefix sum on tree to obtain the distance
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
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

vector<vector<int> > adj;

namespace LCA1 {
    int n, l;
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
    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    // Assume node id starts from 0
    void preprocess(int number_of_nodes) {
        n = number_of_nodes;
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.resize(n, vector<int>(l + 1));
    }
    void init(int root) { dfs(root, root); }
}

namespace PrefixSumTree {
    vector<ll> pre;
    vector<bool> vis;
    void init(int n) {
        vis.resize(n, false);
        pre.resize(n);
    }
    void dfs(int u, ll currSum) {
        for (const auto &v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                pre[v] = currSum + 1;
                dfs(v, pre[v]);
            }
        }
    }
    // Query the distance from u to v:
    // dist(u, v) = pre[u] + pre[v] - 2*pre[lca(u, v)]
    ll dist(int u, int v) {
        return pre[u] + pre[v] - 2*pre[LCA1::lca(u, v)];
    }
}

vector<int> father;

int getRoot(int u) {
    if (father.at(u) == -1) return u;
    return getRoot(father.at(u));
}

int main() {

    int n, u = 0, v = 0;
    IO::read(n);
    LCA1::preprocess(n);
    PrefixSumTree::init(n);
    father.resize(n, -1);
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        IO::read(u, v);
        --u;
        --v;
        father.at(v) = u;
        adj.at(u).emplace_back(v);
        adj.at(v).emplace_back(u);
    }
    int root = getRoot(u);
    PrefixSumTree::vis.at(root) = true;
    PrefixSumTree::dfs(root, 0);
    LCA1::init(root);
    int q;
    IO::read(q);
    while (q--) {
        IO::read(u, v);
        --u; --v;
        IO::writeln(PrefixSumTree::dist(u, v));
    }

    return 0;
}
