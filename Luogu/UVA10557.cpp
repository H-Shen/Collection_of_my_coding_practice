#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAX_ROOMS = 105;
constexpr int SOURCE = 1;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

template<size_t N>
struct TransitiveClosure {
    bitset<N> reach[N];
    void floyd_warshall(int n) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                if (reach[i][k]) {
                    reach[i] |= reach[k];    // reach[i] = reach[i] | reach[k];
                }
            }
        }
    }
    void reset() {
        for (size_t i = 0; i < N; ++i) {
            reach[i].reset();
        }
    }
};

TransitiveClosure<MAX_ROOMS> tc;
int n, w, m, u, v;

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
        dis.resize(number_of_nodes + 5, -INF);
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
        bitset<MAX_ROOMS> in_queue;
        queue<int> q;
        q.push(source);
        in_queue[source] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (const auto &i : adj.at(u)) {
                int v = i.first;
                int w = i.second;
                if (dis.at(v) < dis.at(u) + w && dis.at(u) + w > 0) {
                    dis.at(v) = dis.at(u) + w;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                        ++cnt.at(v);
                        if (cnt.at(v) > number_of_nodes) {
                            // a positive cycle exists in v, which means if we
                            // starts from 1 we will end in a positive cycle,
                            // we can check the connectivity from 1 to n by
                            // Floyd's transitive closure
                            return tc.reach[v][n];
                        }
                    }
                }
            }
        }
        return dis.at(n) > 0;
    }
}

int main() {

    while (true) {
        IO::read(n);
        if (n == -1) break;
        SSSP_SPFA::init(n, SOURCE);
        for (int i = 1; i <= n; ++i) {
            tc.reach[i][i] = true;
        }
        for (int i = 1; i <= n; ++i) {
            u = i;
            IO::read(w, m);
            for (int j = 0; j < m; ++j) {
                IO::read(v);
                SSSP_SPFA::add_edge(u, v, w);
                tc.reach[u][v] = true;
            }
        }
        tc.floyd_warshall(n);
        // Case 1: cannot travel from 1 to n
        if (!tc.reach[1][n]) {
            puts("hopeless");
        }
        // Case 2: can travel from 1 to n
        else {
            SSSP_SPFA::dis.at(1) = 100;
            if (SSSP_SPFA::spfa()) {
                puts("winnable");
            } else {
                puts("hopeless");
            }
        }
        // reset
        tc.reset();
        SSSP_SPFA::reset();
    }
    return 0;
}