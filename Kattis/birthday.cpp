// https://open.kattis.com/problems/birthday

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

// Find cut vertices and bridges in an undirected graph in O(m+n)
namespace CutVertexAndBridges {

    int n; // number of nodes
    vector<vector<int>> adj; // adjacency list of graph
    vector<bool> visited;
    vector<bool> isCutVertex;
    vector<int> tin, low;
    int timer;
    bool hasBridge;

    void init(int number_of_nodes) {

        decltype(adj)().swap(adj);
        decltype(visited)().swap(visited);
        decltype(isCutVertex)().swap(isCutVertex);
        decltype(tin)().swap(tin);
        decltype(low)().swap(low);
        hasBridge = false;
        timer = 0;

        n = number_of_nodes;
        adj.resize(n);
        visited.resize(n, false);
        isCutVertex.resize(n, false);
        tin.resize(n);
        low.resize(n);
    }

    void dfs(int u, int p = -1) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;
        for (const auto v : adj[u]) {
            if (v == p) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    hasBridge = true;
                    return;
                }
                if (low[v] >= tin[u] && p != -1)
                    isCutVertex[u] = true;
                ++children;
            }
        }
        if (p == -1 && children > 1)
            isCutVertex[u] = true;
    }

    void findCutVerticesAndBridges() {
        timer = 0;
        visited.resize(n, false);
        tin.resize(n, -1);
        low.resize(n, -1);
        isCutVertex.resize(n, false);
        // Assume node id starts from 0
        for (int i = 0; i < n; ++i) {
            if (hasBridge) break;
            if (!visited[i]) dfs(i);
        }
    }
}

int n, m, u, v;

int main() {

    while (true) {
        IO::read(n, m);
        if (n == 0 && m == 0) break;
        CutVertexAndBridges::init(n);
        while (m--) {
            IO::read(u, v);
            CutVertexAndBridges::adj[u].emplace_back(v);
            CutVertexAndBridges::adj[v].emplace_back(u);
        }
        CutVertexAndBridges::findCutVerticesAndBridges();
        if (CutVertexAndBridges::hasBridge) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
