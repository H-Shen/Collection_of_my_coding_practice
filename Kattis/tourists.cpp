// https://open.kattis.com/problems/tourists

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

vector<vector<int>> adj;

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

int n, root;
vector<bool> exist;
vector<int> pre;
vector<int> father;

int dist(int u, int v) {
    int lca = LCA1::lca(u, v);
    if (lca == root) {
        return pre.at(u) + pre.at(v) - pre.at(lca);
    }
    return pre.at(u) + pre.at(v) - pre.at(lca) - pre.at(father.at(lca));
}

void dfs(int u, int father_of_u, int current_sum) {
    pre.at(u) = current_sum + 1;
    for (const auto &v : adj.at(u)) {
        if (v != father_of_u) {
            dfs(v, u, pre.at(u));
            father.at(v) = u;
        }
    }
}


int main() {

    int u, v;
    IO::read(n);
    exist.resize(n + 1, false);
    pre.resize(n + 1);
    father.resize(n + 1);
    LCA1::preprocess(n + 5);
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        IO::read(u, v);
        exist.at(u) = true;
        exist.at(v) = true;
        adj.at(u).emplace_back(v);
        adj.at(v).emplace_back(u);
    }
    root = u;
    dfs(root, -1, 0);
    LCA1::init(root);
    ll counter = 0;
    for (u = 1; u <= n; ++u) {
        if (exist[u]) {
            for (int multi = 2; ; ++multi) {
                v = multi * u;
                if (v > n) {
                    break;
                }
                if (exist[v]) {
                    counter += dist(u, v);
                }
            }
        }
    }
    IO::writeln(counter);
    return 0;
}
