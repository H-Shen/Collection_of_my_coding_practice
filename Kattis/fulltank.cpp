// https://open.kattis.com/problems/fulltank

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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

namespace SSSP {

    constexpr int INF = 0x3f3f3f3f;

    struct Node {
        bool operator==(const Node &rhs) const {
            return location == rhs.location &&
                   current_fuel == rhs.current_fuel;
        }
        int location;
        int current_fuel;
        explicit Node(int location, int current_fuel) : location(location), current_fuel(current_fuel) {}
        Node() = default;
    };
    vector<Node> id2node;
    vector<vector<pair<int, int> > > adj;
    int id = 0;

    void reset() {
        vector<Node>().swap(id2node);
        decltype(adj)().swap(adj);
        id = 0;
    }

    int dijkstra(int source, int dest, int c) {

        vector<int> dist(id, INF);
        dist.at(source*(c+1)+0) = 0;
        // source: Node(s, 0)
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        pq.push({0, source*(c+1)+0});
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dist.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : adj.at(v)) {
                if (dist.at(to) > dist.at(v) + weight) {
                    dist.at(to) = dist.at(v) + weight;
                    pq.push({dist.at(to), to});
                }
            }
        }
        // dist: Node(t, any)
        int minCost = INF;
        for (int i = 0; i <= c; ++i) {
            minCost = min(minCost, dist.at(dest*(c+1)+i));
        }
        return minCost;
    }
}

vector<int> price;
vector<vector<pair<int, int> > > adj;
int n, m, q, u, v, d, s, t, c;

int main() {

    IO::read(n, m);
    price.resize(n);
    adj.resize(n);
    for (auto &i : price) IO::read(i);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, d);
        adj.at(u).emplace_back(v, d);
        adj.at(v).emplace_back(u, d);
    }
    IO::read(q);
    while (q--) {
        IO::read(c, s, t);
        // create all states
        SSSP::Node node;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= c; ++j) {
                node.location = i;
                node.current_fuel = j;
                // node id: node.location*(c+1)+node.current_fuel
                SSSP::id2node.emplace_back(node);
                ++SSSP::id;
            }
        }
        SSSP::adj.resize(SSSP::id);
        // create all edges
        // Node(x, fuel) --> Node(x, fuel+1) (0<=fuel<c, 0<=x<=n-1), weight = price[x]
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= c - 1; ++j) {
                u = i*(c+1)+j;
                v = u + 1;
                SSSP::adj.at(u).emplace_back(v, price.at(i));
            }
        }
        // Node(x, fuel) --> Node(adj.x, fuel - cost) (fuel>=cost, 0<=x<=n-1), weight = 0
        for (int i = 0; i < n; ++i) {
            for (const auto &[j, cost] : adj.at(i)) {
                for (int fuel = c; fuel - cost >= 0; --fuel) {
                    u = i*(c+1)+fuel;
                    v = j*(c+1)+(fuel-cost);
                    SSSP::adj.at(u).emplace_back(v, 0);
                }
            }
        }
        int answer = SSSP::dijkstra(s, t, c);
        if (answer == SSSP::INF) {
            puts("impossible");
        } else {
            IO::writeln(answer);
        }
        SSSP::reset();
    }


    return 0;
}
