// https://open.kattis.com/problems/dragonball1
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int PLACES = 7;

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

namespace SSSP_Dijkstra_1 {

    constexpr ll INF = 0x3f3f3f3f3f3f3f; //  A weight indicates two nodes have no paths between them
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
        dis.at(source) = 0;
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
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

int main() {

    int n, m, u, v;
    ll w;
    IO::read(n, m);
    SSSP_Dijkstra_1::init(n);
    while (m--) {
        IO::read(u, v, w);
        SSSP_Dijkstra_1::add_edge(u, v, w);
        SSSP_Dijkstra_1::add_edge(v, u, w);
    }
    unordered_map<int, vector<ll>, custom_hash> place2dis;
    vector<int> places(PLACES);
    for (int i = 0; i < PLACES; ++i) {
        IO::read(places.at(i));
        place2dis[places.at(i)] = SSSP_Dijkstra_1::dijkstra(places.at(i));
    }
    // start enumeration
    int source = 1;
    vector<ll> dis_from_original = SSSP_Dijkstra_1::dijkstra(source);
    sort(places.begin(), places.end());
    ll minimum_cost = SSSP_Dijkstra_1::INF;
    ll current_cost, temp;
    bool have_answer;
    do {
        have_answer = true;
        temp = dis_from_original.at(places.at(0));
        if (temp == SSSP_Dijkstra_1::INF) {
            continue;
        }
        current_cost = temp;
        for (int i = 1; i < PLACES; ++i) {
            temp = place2dis[places.at(i - 1)].at(places.at(i));
            if (temp == SSSP_Dijkstra_1::INF) {
                have_answer = false;
                break;
            }
            current_cost += temp;
        }
        if (!have_answer) {
            continue;
        }
        minimum_cost = min(minimum_cost, current_cost);
    } while (next_permutation(places.begin(), places.end()));
    if (minimum_cost == SSSP_Dijkstra_1::INF) {
        IO::writeln(-1);
    } else {
        IO::writeln(minimum_cost);
    }

    return 0;
}
