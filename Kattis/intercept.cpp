// https://open.kattis.com/problems/intercept

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

namespace SSSP_Dijkstra {

    constexpr ll LINF = 4e18; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, ll> > > adj, adj_rev; // The adjacency list of the graph
    int number_of_nodes;

    inline void
    init(int n) {
        number_of_nodes = n;
        adj.resize(number_of_nodes);
        adj_rev.resize(number_of_nodes);
    }

    inline void
    add_edge(int u, int v, ll w) {
        adj.at(u).emplace_back(make_pair(v, w));
        adj_rev.at(v).emplace_back(make_pair(u, w));
    }

    inline vector<ll>
    dijkstra(int source, const vector<vector<pair<int, ll> > > &Adj) {
        vector<ll> dis(number_of_nodes, LINF);
        dis.at(source) = 0;
        std::priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            ll d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : Adj.at(v)) {
                if (dis.at(to) > dis.at(v) + weight) {
                    dis.at(to) = dis.at(v) + weight;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
        return dis;
    }
}

int n, m, u, v, s, t;
ll w;

struct Node {
    Node(int u, int v, ll w) : u(u), v(v), w(w) {}

    int u, v;
    ll w;
};

// Find cut vertices and bridges in an undirected graph in O(m+n)
namespace CutVertexAndBridges {

    int n; // number of nodes
    vector<bool> visited;
    vector<bool> isCutVertex;
    vector<pair<int, int> > bridges;
    vector<int> tin, low;
    int timer;

    void reset() {
        decltype(visited)().swap(visited);
        decltype(isCutVertex)().swap(isCutVertex);
        decltype(bridges)().swap(bridges);
        decltype(tin)().swap(tin);
        decltype(low)().swap(low);
    }

    void init(int number_of_nodes) {
        n = number_of_nodes;
        visited.resize(n, false);
        isCutVertex.resize(n, false);
        tin.resize(n);
        low.resize(n);
    }

    void dfs(const vector<vector<int> > &adj, int u, int p = -1) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;
        for (const auto &v : adj[u]) {
            if (v == p) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(adj, v, u);
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

    void findCutVerticesAndBridges(const vector<vector<int> > &adj) {
        timer = 0;
        visited.resize(n, false);
        tin.resize(n, -1);
        low.resize(n, -1);
        isCutVertex.resize(n, false);
        vector<pair<int, int> >().swap(bridges);
        // Assume node id starts from 0
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) dfs(adj, i);
        }
    }
}

int main() {

    IO::read(n, m);
    SSSP_Dijkstra::init(n);

    vector<Node> edges;
    while (m--) {
        IO::read(u, v, w);
        edges.emplace_back(u, v, w);
        SSSP_Dijkstra::add_edge(u, v, w);
    }
    IO::read(s, t);
    auto dist_from_s = SSSP_Dijkstra::dijkstra(s, SSSP_Dijkstra::adj);
    auto dist_from_t = SSSP_Dijkstra::dijkstra(t, SSSP_Dijkstra::adj_rev);
    vector<pair<int, int> > newEdges;

    for (const auto &[a, b, c] : edges) {
        if (dist_from_s.at(a) + c + dist_from_t.at(b) == dist_from_s.at(t)) {
            newEdges.emplace_back(a, b);
        }
        else if (dist_from_t.at(a) + c + dist_from_s.at(b) == dist_from_s.at(t)) {
            newEdges.emplace_back(a, b);
        }
    }
    vector<vector<int> > newAdj(n);
    CutVertexAndBridges::init(n);
    for (const auto &[a, b] : newEdges) {
        newAdj.at(a).emplace_back(b);
        newAdj.at(b).emplace_back(a);
    }
    CutVertexAndBridges::findCutVerticesAndBridges(newAdj);
    for (int i = 0; i < n; ++i) {
        if (CutVertexAndBridges::isCutVertex.at(i) || i == s || i == t) {
            IO::write(i);
            putchar_unlocked(' ');
        }
    }

    return 0;
}
