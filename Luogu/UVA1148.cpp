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
    dijkstra(int source, int dest) {
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
            for (const auto &i : adj.at(v)) {
                int to = i;
                int weight = 1;
                if (dist.at(to) > dist.at(v) + weight) {
                    dist.at(to) = dist.at(v) + weight;
                    pq.push({dist.at(to), to});
                }
            }
        }
        return dist.at(dest);
    }
}

int n;

int main() {

    int t, u, v, m, c1, c2;
    IO::read(t);
    bool first_case = true;
    while (t--) {
        IO::read(n);
        SSSP_Dijkstra::init(n);
        for (int i = 0; i < n; ++i) {
            IO::read(u, m);
            for (int j = 0; j < m; ++j) {
                IO::read(v);
                SSSP_Dijkstra::adj.at(u).emplace_back(v);
                SSSP_Dijkstra::adj.at(v).emplace_back(u);
            }
        }
        IO::read(c1, c2);
        if (first_case) {
            first_case = false;
        } else {
            putchar_unlocked('\n');
        }
        IO::write(c1);
        putchar_unlocked(' ');
        IO::write(c2);
        putchar_unlocked(' ');
        IO::writeln(SSSP_Dijkstra::dijkstra(c1, c2) - 1);
    }

    return 0;
}