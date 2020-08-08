#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

    constexpr ll INF = 0x3f3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, ll> > > adj; // The adjacency list of the graph
    int number_of_nodes;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
    }


    inline void
    add_edge(int u, int v, ll w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline vector<ll>
    dijkstra(int source) {
        vector<ll> dis(number_of_nodes + 5, INF);
        dis.at(source) = 0.0;
        std::priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            ll d_v = pq.top().first;
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
        return dis;
    }
}

constexpr int MAXN = 5;
constexpr int MAX_STATIONS = 50005;
int n, m;
int original = 1;
array<int, MAXN> positions;
vector<ll> dist_from_original;
vector<vector<ll> > dist_from_positions(MAX_STATIONS);

int main() {

    IO::read(n, m);
    for (int i = 0; i < MAXN; ++i) {
        IO::read(positions.at(i));
    }
    int x, y;
    ll t;
    SSSP_Dijkstra_1::init(n);
    while (m--) {
        IO::read(x, y, t);
        SSSP_Dijkstra_1::add_edge(x, y, t);
        SSSP_Dijkstra_1::add_edge(y, x, t);
    }
    dist_from_original = SSSP_Dijkstra_1::dijkstra(original);
    sort(positions.begin(), positions.end());
    for (const auto &i : positions) {
        dist_from_positions.at(i) = SSSP_Dijkstra_1::dijkstra(i);
    }
    ll min_total_dist = numeric_limits<ll>::max();
    ll total_dist;
    do {
        total_dist = 0;
        total_dist += dist_from_original.at(positions.front());
        for (int i = 0; i < MAXN - 1; ++i) {
            total_dist += dist_from_positions.at(positions.at(i)).at(
                    positions.at(i + 1));
        }
        min_total_dist = min(min_total_dist, total_dist);
    } while (next_permutation(positions.begin(), positions.end()));
    IO::writeln(min_total_dist);

    return 0;
}
