// https://open.kattis.com/problems/detour

#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

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
    constexpr ll INF = 4e18;
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
    vector<ll>
    dijkstra(int source, bool store_path = false) {
        // dist.at(u) = the shortest distance from source to u
        vector<ll> dist(number_of_nodes, INF);
        dist.at(source) = 0;
        std::priority_queue<pair<int, ll>, vector<pair<int, ll> >, greater<> > pq;
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                        time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                        time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};
unordered_set<pair<int, int>, custom_hash> unset;

namespace SSSP_Dijkstra2 {
    constexpr ll INF = 4e18;

    int number_of_nodes;
    vector<int> prev;
    void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
        SSSP_Dijkstra::adj.resize(number_of_nodes);
        if (store_path) {
            prev.resize(number_of_nodes, -1);
        }
    }
    ll
    dijkstra(int source, int dest, bool store_path = false) {
        // dist.at(u) = the shortest distance from source to u
        vector<ll> dist(number_of_nodes, INF);
        dist.at(source) = 0;
        std::priority_queue<pair<int, ll>, vector<pair<int, ll> >, greater<> > pq;
        pq.push(make_pair(dist.at(source), source));
        while (!pq.empty()) {
            ll d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dist.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : SSSP_Dijkstra::adj.at(v)) {
                if (unset.find({v, to}) != unset.end()) {
                    continue;
                }
                if (dist.at(to) > dist.at(v) + weight) {
                    dist.at(to) = dist.at(v) + weight;
                    if (store_path) {
                        prev.at(to) = v;
                    }
                    pq.push({dist.at(to), to});
                }
            }
        }
        return dist.at(dest);
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


int main() {

    int n, m, u, v;
    ll w;
    IO::read(n, m);
    SSSP_Dijkstra::init(n, true);
    while (m--) {
        IO::read(u, v, w);
        SSSP_Dijkstra::adj.at(u).emplace_back(v, w);
        SSSP_Dijkstra::adj.at(v).emplace_back(u, w);
    }
    auto dist = SSSP_Dijkstra::dijkstra(1, true);
    if (dist.at(0) == SSSP_Dijkstra::INF) { // prune
        puts("impossible");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (const auto &[j, weight] : SSSP_Dijkstra::adj.at(i)) {
            if (SSSP_Dijkstra::prev.at(i) == j) {
                // The correct way to obtain an edge that is in the shortest path from some source to all other nodes
                // Also, we cant remove {i, j} from the graph directly, we should store them and skip them later
                unset.insert({i, j});
            }
        }
    }
    SSSP_Dijkstra2::init(n, true);
    ll length = SSSP_Dijkstra2::dijkstra(0, 1, true);
    if (length == SSSP_Dijkstra2::INF) {
        puts("impossible");
    } else {
        auto path = SSSP_Dijkstra2::get_path(1);
        IO::write(path.size());
        for (const auto &i : path) {
            putchar_unlocked(' ');
            IO::write(i);
        }
        putchar_unlocked('\n');
    }

    return 0;
}
