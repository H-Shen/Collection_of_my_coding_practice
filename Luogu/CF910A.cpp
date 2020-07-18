#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 105;

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

namespace SSSP1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    vector<int> prev;   // an auxiliary container to store the path
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
        dis.resize(number_of_nodes + 5, INF);
        if (store_path) {
            prev.resize(number_of_nodes, -1);
        }
    }

    inline void
    reset(bool store_path = false) {
        fill(dis.begin(), dis.end(), INF);
        pq = decltype(pq)();
        if (store_path) {
            fill(prev.begin(), prev.end(), -1);
        }
    }

    inline void
    add_edge(int u, int v) {
        adj[u].insert(v);
    }

    inline void
    dijkstra(bool store_path = false) {
        dis.at(source) = 0;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &to : adj[v]) {
                if (dis.at(to) > dis.at(v) + 1) {
                    dis.at(to) = dis.at(v) + 1;
                    if (store_path) {
                        prev.at(to) = v;
                    }
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
    inline vector<int>
    get_path(int destination) {
        vector<int> path;
        for (; destination != -1; destination = prev.at(destination)) {
            path.emplace_back(destination);
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

bitset<MAXN> vis;
int n, d;
void dfs(int last_pos, int current_pos) {
    if (last_pos != -1) {
        SSSP1::add_edge(last_pos, current_pos);
    }
    if (vis[current_pos]) {
        return;
    }
    vis[current_pos] = true;
    if (current_pos == n) {
        return;
    }
    int new_pos;
    for (int step = 1; step <= d; ++step) {
        new_pos = current_pos + step;
        if (new_pos >= 1 && new_pos <= n) {
            dfs(current_pos, new_pos);
        }
    }
}

int main(int argc, char *argv[]) {

    string s;
    cin >> n >> d >> s;
    for (int i = 1; i <= n; ++i) {
        if (s.at(i - 1) == '0') {
            vis[i] = true;
        }
    }
    dfs(-1, 1);
    SSSP1::source = 1;
    SSSP1::init(n);
    SSSP1::dijkstra();
    if (SSSP1::dis.at(n) == SSSP1::INF) {
        cout << -1 << '\n';
    } else {
        cout << SSSP1::dis.at(n) << '\n';
    }

    return 0;
}