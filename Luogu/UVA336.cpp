#include <bits/stdc++.h>

using namespace std;
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
    constexpr int INF = 0x3f3f3f3f;
    // The adjacency list of the graph
    vector<vector<int> > adj;
    int number_of_nodes;
    void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        vector<vector<int> >().swap(adj);
        adj.resize(number_of_nodes);
    }
    int
    dijkstra(int source, int ttl) {
        vector<int> dist(number_of_nodes, INF);
        dist.at(source) = 0;
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push(make_pair(dist.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dist.at(v)) {
                continue;
            }
            for (const auto &to : adj.at(v)) {
                if (dist.at(to) > dist.at(v) + 1) {
                    dist.at(to) = dist.at(v) + 1;
                    pq.push({dist.at(to), to});
                }
            }
        }
        int counter = 0;
        for (const auto &i : dist) {
            if (i > ttl) {
                ++counter;
            }
        }
        return counter;
    }
}

int main() {

    int m, u, v;
    int kase = 1;
    while (true) {
        IO::read(m);
        if (m == 0) break;
        unordered_map<int, int> node2id;
        vector<pair<int, int> > edges;
        int id = 0;
        while (m--) {
            IO::read(u, v);
            if (node2id.find(u) == node2id.end()) {
                node2id[u] = id;
                ++id;
            }
            if (node2id.find(v) == node2id.end()) {
                node2id[v] = id;
                ++id;
            }
            edges.emplace_back(node2id[u], node2id[v]);
        }
        SSSP_Dijkstra::init(id);
        for (const auto &i : edges) {
            u = i.first;
            v = i.second;
            SSSP_Dijkstra::adj.at(u).emplace_back(v);
            SSSP_Dijkstra::adj.at(v).emplace_back(u);
        }
        int s, ttl;
        while (true) {
            IO::read(s, ttl);
            if (s == 0 && ttl == 0) break;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", kase, SSSP_Dijkstra::dijkstra(node2id[s], ttl), s, ttl);
            ++kase;
        }
    }
    return 0;
}