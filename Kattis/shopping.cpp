// https://open.kattis.com/problems/shopping

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
    constexpr ll LINF = 4e18;
    // The adjacency list of the graph
    vector<vector<pair<int, ll> > > adj;
    int number_of_nodes;
    vector<int> prev;
    void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes);
        if (store_path) {
            prev.resize(number_of_nodes, -1);
        }
    }
    void
    reset(bool store_path = false) {
        if (store_path) {
            fill(prev.begin(), prev.end(), -1);
        }
    }
    void
    add_edge(int u, int v, ll w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }
    vector<ll>
    dijkstra(int source, bool store_path = false) {
        // dist.at(u) = the shortest distance from source to u
        vector<ll> dist(number_of_nodes, LINF);
        dist.at(source) = 0;
        std::priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
        pq.push(make_pair(dist.at(source), source));
        while (!pq.empty()) {
            ll d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dist.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : adj.at(v)) {
                if (dist.at(to) > dist.at(v) + weight) {
                    dist.at(to) = dist.at(v) + weight;
                    if (store_path) {
                        prev.at(to) = v;
                    }
                    pq.push({dist.at(to), to});
                }
            }
        }
        return dist;
    }
    vector<int>
    get_path(int destination) {
        vector<int> path;
        for (; destination != -1; destination = prev.at(destination)) {
            path.emplace_back(destination);
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

int n, m, source, u, v;
ll w;

int main() {

    IO::read(n, m);
    source = 0;
    SSSP_Dijkstra::init(n);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        SSSP_Dijkstra::add_edge(u, v, w);
        SSSP_Dijkstra::add_edge(v, u, w);
    }
    int s;
    IO::read(s);
    vector<int> stations(s);
    for (auto &i : stations) IO::read(i);
    sort(stations.begin(), stations.end());
    auto dist_from_source = SSSP_Dijkstra::dijkstra(source);
    unordered_map<int, vector<ll> > unmap;
    for (const auto &i : stations) {
        unmap[i] = SSSP_Dijkstra::dijkstra(i);
    }
    ll minDist = numeric_limits<ll>::max();
    ll currentMinDist;
    do {
        currentMinDist = dist_from_source.at(stations.front());
        for (int i = 0; i < s - 1; ++i) {
            currentMinDist += unmap[stations.at(i)].at(stations.at(i + 1));
        }
        currentMinDist += unmap[stations.at(s - 1)].at(source);
        minDist = min(minDist, currentMinDist);
    } while (next_permutation(stations.begin(), stations.end()));
    IO::writeln(minDist);
    return 0;
}
