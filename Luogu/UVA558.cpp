#include <bits/stdc++.h>

using namespace std;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

namespace SSSP_SPFA {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    reset() {
        vector<vector<pair<int, int> > >().swap(adj);
        vector<int>().swap(dis);
        number_of_nodes = 0;
        source = 0;
    }

    inline void
    init(int n, int s) {
        vector<vector<pair<int, int> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    // O(mn)
    inline bool
    spfa() {
        vector<int> cnt(number_of_nodes + 5);
        vector<bool> in_queue(number_of_nodes + 5, false);
        queue<int> q;
        q.push(source);
        in_queue.at(source) = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue.at(u) = false;
            int v, w;
            for (const auto &i : adj.at(u)) {
                v = i.first;
                w = i.second;
                if (dis.at(v) > dis.at(u) + w) {
                    dis.at(v) = dis.at(u) + w;
                    if (!in_queue.at(v)) {
                        q.push(v);
                        in_queue.at(v) = true;
                        ++cnt.at(v);
                        if (cnt.at(v) > number_of_nodes) {
                            return false;   // a negative cycle exists
                        }
                    }
                }
            }
        }
        return true;
    }
}


int main() {

    int t, n, m, u, v, w;
    int source = 0;
    IO::read(t);
    while (t--) {
        IO::read(n, m);
        SSSP_SPFA::init(n, source);
        while (m--) {
            IO::read(u, v, w);
            SSSP_SPFA::add_edge(u, v, w);
        }
        if (!SSSP_SPFA::spfa()) {
            printf("possible\n");
        } else {
            printf("not possible\n");
        }
        SSSP_SPFA::reset();
    }

    return 0;
}
