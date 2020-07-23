#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(r) = the shortest distance from source to r
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

constexpr int STEPS = 4;
constexpr int MAX_SIZE = 120;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int r, c;
bitset<MAX_SIZE> vis[MAX_SIZE];
vector<vector<char> > M;
int origin_i, origin_j, dest_i, dest_j;

void dfs(int last, int i, int j) {
    if (M[i][j] == '*') {
        return;
    }
    int pos = i * c + j;
    if (last != -1) {
        SSSP_Dijkstra_1::add_edge(last, pos);
    }
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = true;
    if (i == dest_i && j == dest_j) {
        return;
    }
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
            dfs(pos, new_i, new_j);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    dest_i = r - 1;
    dest_j = c - 1;
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    SSSP_Dijkstra_1::init(r * c, true);
    SSSP_Dijkstra_1::source = origin_i * c + origin_j;
    dfs(-1, origin_i, origin_j);
    SSSP_Dijkstra_1::dijkstra(true);
    auto path = SSSP_Dijkstra_1::get_path(dest_i * c + dest_j);
    for (const auto &i : path) {
        cout << i / c + 1 << ' ' << i % c + 1 << '\n';
    }

    return 0;
}