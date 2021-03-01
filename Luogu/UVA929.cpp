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
        vector<vector<pair<int, int> > >().swap(adj);
        adj.resize(number_of_nodes);
    }
    int
    dijkstra(int source, int dest, int initial_cost) {
        vector<int> dist(number_of_nodes, INF);
        dist.at(source) = initial_cost;
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
                int to = i.first;
                int weight = i.second;
                if (dist.at(to) > dist.at(v) + weight) {
                    dist.at(to) = dist.at(v) + weight;
                    pq.push({dist.at(to), to});
                }
            }
        }
        return dist.at(dest);
    }
}

constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
vector<vector<int> > M;
int r, c;

int convert(int r_, int c_) {
    return r_*c+c_;
}

int main() {

    int t;
    IO::read(t);
    while (t--) {
        decltype(M)().swap(M);
        IO::read(r, c);
        M.resize(r, vector<int>(c));
        for (auto &i : M) for (auto &j : i) IO::read(j);
        //
        SSSP_Dijkstra::init(r * c);
        int new_i, new_j;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
                        SSSP_Dijkstra::adj.at(convert(i, j)).emplace_back(convert(new_i, new_j), M.at(new_i).at(new_j));
                    }
                }
            }
        }
        IO::writeln(SSSP_Dijkstra::dijkstra(convert(0, 0), convert(r-1, c-1), M.at(0).at(0)));
    }


    return 0;
}