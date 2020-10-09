// https://open.kattis.com/problems/beepers
//
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

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<int> > adj; // The adjacency list of the graph
    int number_of_nodes;

    inline void
    init(int n) {
        number_of_nodes = n;
        // clear the containers
        decltype(adj)().swap(adj);
        // initialize the containers
        adj.resize(number_of_nodes + 5);
    }

    inline void
    add_edge(int u, int v) {
        adj.at(u).emplace_back(v);
    }

    inline vector<int>
    dijkstra(int source) {
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        vector<int> dis(number_of_nodes, INF);
        dis.at(source) = 0;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &to : adj.at(v)) {
                if (dis.at(to) > dis.at(v) + 1) {
                    dis.at(to) = dis.at(v) + 1;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
        return dis;
    }
}

constexpr int STEPS = 4;
constexpr int MAXN = 30;
constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {-1, 1, 0, 0};

bitset<MAXN> vis[MAXN];
int r, c, original_i, original_j;

void dfs(int last_i, int last_j, int cur_i, int cur_j) {
    if (!(last_i == -1 && last_j == -1)) {
        SSSP_Dijkstra_1::add_edge(last_i * c + last_j, cur_i * c + cur_j);
        SSSP_Dijkstra_1::add_edge(cur_i * c + cur_j, last_i * c + last_j);
    }
    if (vis[cur_i][cur_j]) {
        return;
    }
    vis[cur_i][cur_j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = cur_i + dx[step];
        new_j = cur_j + dy[step];
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
            dfs(cur_i, cur_j, new_i, new_j);
        }
    }
}

int main() {

    int t, m, beeper_i, beeper_j;
    IO::read(t);
    while (t--) {
        
        // reading chess
        IO::read(r, c);
        r += 5;
        c += 5;
        SSSP_Dijkstra_1::init(r * c);
        IO::read(original_i, original_j);
        
        // start dfs
        dfs(-1, -1, original_i, original_j);
        
        // reading beepers
        IO::read(m);
        vector<pair<int, vector<int> > > dist_from_beepers(m);
        for (auto &i : dist_from_beepers) {
            IO::read(beeper_i, beeper_j);
            i.first = beeper_i * c + beeper_j;
            i.second = SSSP_Dijkstra_1::dijkstra(beeper_i * c + beeper_j);
        }
        pair<int, vector<int> > dist_from_original{original_i * c + original_j,
                                                   SSSP_Dijkstra_1::dijkstra(
                                                           original_i * c + original_j)};

        // start enumeration
        int minimum_cost = SSSP_Dijkstra_1::INF;
        int current_cost;
        vector<int> beeper_index(m);
        iota(beeper_index.begin(), beeper_index.end(), 0);
        do {
            current_cost = dist_from_original.second.at(dist_from_beepers.at(beeper_index.at(0)).first);
            for (int i = 1; i < m; ++i) {
                current_cost += dist_from_beepers.at(beeper_index.at(i - 1)).second.at(dist_from_beepers.at(beeper_index.at(i)).first);
            }
            current_cost += dist_from_beepers.at(beeper_index.at(m - 1)).second.at(dist_from_original.first);
            minimum_cost = min(minimum_cost, current_cost);
        } while (next_permutation(beeper_index.begin(), beeper_index.end()));
        IO::writeln(minimum_cost);
        
        // clear
        for (auto &i : vis) {
            i.reset();
        }
    }
    return 0;
}
