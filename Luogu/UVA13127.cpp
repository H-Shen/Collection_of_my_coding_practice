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
    vector<vector<pair<int, int> > > adj;
    int number_of_nodes;
    void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        decltype(adj)().swap(adj);
        adj.resize(number_of_nodes);
    }
    vector<int>
    dijkstra(int source) {
        // dist.at(u) = the shortest distance from source to u
        vector<int> dist(number_of_nodes, INF);
        dist.at(source) = 0;
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
        pq.push(make_pair(dist.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dist.at(v)) {
                continue;
            }
            int to, weight;
            for (const auto &i : adj.at(v)) {
                to = i.first;
                weight = i.second;
                if (dist.at(to) > dist.at(v) + weight) {
                    dist.at(to) = dist.at(v) + weight;
                    pq.push({dist.at(to), to});
                }
            }
        }
        return dist;
    }
}

int n, m, b, p, u, v, w;

int main() {
    freopen("/Users/hshen/myCpp/input", "r", stdin);
    while (IO::can_read(n, m, b, p)) {
        SSSP_Dijkstra::init(n);
        for (int i = 0; i < m; ++i) {
            IO::read(u, v, w);
            SSSP_Dijkstra::adj.at(u).emplace_back(v, w);
            SSSP_Dijkstra::adj.at(v).emplace_back(u, w);
        }
        vector<int> banks(b);
        for (auto &i : banks) IO::read(i);
        if (p != 0) {
            vector<int> polices(p);
            for (auto &i : polices) IO::read(i);
            unordered_map<int, vector<int> > unmap;
            for (const auto &i : banks) {
                unmap[i] = SSSP_Dijkstra::dijkstra(i);
            }
            int maxMinDist = -1;
            for (const auto &i : unmap) {
                int currentMinDist = numeric_limits<int>::max();
                for (const auto &j : polices) {
                    currentMinDist = min(currentMinDist, i.second.at(j));
                }
                maxMinDist = max(maxMinDist, currentMinDist);
            }
            vector<int> output;
            for (const auto &i : unmap) {
                int currentMinDist = numeric_limits<int>::max();
                for (const auto &j : polices) {
                    currentMinDist = min(currentMinDist, i.second.at(j));
                }
                if (currentMinDist == maxMinDist) {
                    output.emplace_back(i.first);
                }
            }
            IO::write(output.size());
            putchar_unlocked(' ');
            if (maxMinDist == SSSP_Dijkstra::INF) {
                putchar_unlocked('*');
                putchar_unlocked('\n');
            } else {
                IO::writeln(maxMinDist);
            }
            sort(output.begin(), output.end());
            for (size_t i = 0; i != output.size(); ++i) {
                if (i > 0) {
                    putchar_unlocked(' ');
                }
                IO::write(output.at(i));
            }
            putchar_unlocked('\n');
        }
        else {
            IO::write(b);
            putchar_unlocked(' ');
            putchar_unlocked('*');
            putchar_unlocked('\n');
            sort(banks.begin(), banks.end());
            for (size_t i = 0; i != banks.size(); ++i) {
                if (i > 0) {
                    putchar_unlocked(' ');
                }
                IO::write(banks.at(i));
            }
            putchar_unlocked('\n');
        }
    }

    return 0;
}