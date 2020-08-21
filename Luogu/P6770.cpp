#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll [[maybe_unused]] = long long;
using pii [[maybe_unused]] = pair<int, int>;

namespace IO {
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

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pii> > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    std::priority_queue<pii, vector<pii>, greater<> > pq;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : adj.at(v)) {
                if (dis.at(to) > dis.at(v) + weight) {
                    dis.at(to) = dis.at(v) + weight;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
}

int main() {

    int f, p, c, m, u, v, w;
    IO::read(f, p, c, m);
    SSSP_Dijkstra_1::init(f);
    while (p--) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
        SSSP_Dijkstra_1::add_edge(v, u, w);
    }
    vector<int> dest(c);
    for (auto &i : dest) IO::read(i);
    SSSP_Dijkstra_1::source = 1;
    SSSP_Dijkstra_1::dijkstra();
    int counter = 0;
    vector<int> output;
    for (int i = 0; i < c; ++i) {
        if (SSSP_Dijkstra_1::dis.at(dest.at(i)) <= m) {
            output.emplace_back(i + 1);
            ++counter;
        }
    }
    sort(output.begin(), output.end());
    IO::writeln(counter);
    for (const auto &i : output) {
        IO::writeln(i);
    }

    return 0;
}
