// https://www.luogu.com.cn/problem/U119054

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

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

// Find cut vertices and bridges in an undirected graph in O(m+n)
namespace CutVertexAndBridges {

    int n; // number of nodes
    vector<unordered_set<int> > adj; // adjacency list of graph
    vector<bool> visited;
    vector<bool> isCutVertex;
    vector<pair<int, int> > bridges;
    vector<int> tin, low;
    int timer;

    void reset() {
        decltype(adj)().swap(adj);
        decltype(visited)().swap(visited);
        decltype(isCutVertex)().swap(isCutVertex);
        decltype(bridges)().swap(bridges);
        decltype(tin)().swap(tin);
        decltype(low)().swap(low);
    }

    void init(int number_of_nodes) {
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
                    if (u > v) {
                        bridges.emplace_back(v, u);
                    } else {
                        bridges.emplace_back(u, v);
                    }
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
        vector<pair<int, int> >().swap(bridges);
        // Assume node id starts from 0
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) dfs(i);
        }
    }
}

int n, m, u, v;
vector<ll> w;
vector<ll> result;

int main() {

    IO::read(n, m);
    w.resize(n);
    CutVertexAndBridges::init(n);
    for (auto &i : w) IO::read(i);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v);
        --u;
        --v;
        CutVertexAndBridges::adj.at(u).insert(v);
        CutVertexAndBridges::adj.at(v).insert(u);
    }
    CutVertexAndBridges::findCutVerticesAndBridges();
    for (const auto &[a, b] : CutVertexAndBridges::bridges) {
        CutVertexAndBridges::adj[a].erase(b);
        CutVertexAndBridges::adj[b].erase(a);
    }
    DSU::init(n);
    for (int i = 0; i < n; ++i) {
        for (const auto &j : CutVertexAndBridges::adj[i]) {
            DSU::merge(i, j);
        }
    }
    result.resize(n, -1);
    for (int i = 0; i < n; ++i) {
        int group_id = DSU::find(i);
        if (result.at(group_id) == -1) {
            result.at(group_id) = w.at(i);
        } else {
            result.at(group_id) ^= w.at(i);
        }
    }
    vector<int> output;
    for (int i = 0; i < n; ++i) {
        if (result.at(i) != -1) {
            output.emplace_back(result.at(i));
        }
    }
    sort(output.begin(), output.end());
    for (const auto &i : output) {
        IO::writeln(i);
    }

    return 0;
}
