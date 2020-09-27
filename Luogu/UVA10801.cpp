#include <bits/stdc++.h>

using namespace std;

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

const regex r("\\d+");

vector<int> parse(const string &s) {
    vector<int> result;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
         it != end_it; ++it) {
        result.emplace_back(stoi(it->str()));
    }
    return result;
}

constexpr int K = 600;
constexpr int ONE_MINUTE = 60;

struct Edge {
    explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    int u, v, w;
};

vector<Edge> edges;
vector<unordered_map<int, int, custom_hash> > level2node;
vector<vector<int> > levels;
vector<int> speed;
int node_counter;

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;
    vector<int> dis;    // dis.at(n) = the shortest distance from source to n

    inline void
    init(int n) {
        // clear
        decltype(adj)().swap(adj);
        vector<int>().swap(dis);
        // initialization
        number_of_nodes = n;
        adj.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline void
    dijkstra(int source) {
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        dis.at(source) = 0;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            int to, weight;
            for (const auto &i : adj.at(v)) {
                to = i.first;
                weight = i.second;
                if (dis.at(to) > dis.at(v) + weight) {
                    dis.at(to) = dis.at(v) + weight;
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, length, u, v, w;
    vector<int> temp_vec;
    string s;
    while (cin >> n >> k) {
        speed.resize(n);
        levels.resize(n);
        for (auto &i : speed) cin >> i;
        cin.get();
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            levels.at(i) = parse(s);
        }
        if (k == 0) {
            cout << 0 << '\n';
        } else {
            level2node.resize(n);
            for (int i = 0; i < n; ++i) {
                level2node.at(i)[k] = K;
            }
            for (int i = 0; i < n; ++i) {
                length = static_cast<int>(levels.at(i).size());
                for (int j = 0; j < length - 1; ++j) {
                    u = levels.at(i).at(j);
                    v = levels.at(i).at(j + 1);
                    if (level2node.at(i).find(u) == level2node.at(i).end()) {
                        level2node.at(i)[u] = node_counter;
                        ++node_counter;
                    }
                    if (level2node.at(i).find(v) == level2node.at(i).end()) {
                        level2node.at(i)[v] = node_counter;
                        ++node_counter;
                    }
                    w = (v - u) * speed.at(i);
                    edges.emplace_back(
                            Edge(level2node.at(i)[u], level2node.at(i)[v], w));
                }
            }
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    vector<int> intersection;
                    set_intersection(levels.at(i).begin(), levels.at(i).end(),
                                     levels.at(j).begin(), levels.at(j).end(),
                                     back_inserter(intersection));
                    for (const auto &elem : intersection) {
                        if (elem != 0) {
                            u = level2node.at(i)[elem];
                            v = level2node.at(j)[elem];
                            w = ONE_MINUTE;
                            edges.emplace_back(Edge(u, v, w));
                        }
                    }
                }
            }
            // get the shortest path
            SSSP_Dijkstra_1::init(K);
            for (const auto &i : edges) {
                SSSP_Dijkstra_1::add_edge(i.u, i.v, i.w);
                SSSP_Dijkstra_1::add_edge(i.v, i.u, i.w);
            }
            vector<int> level0;
            for (auto &i : level2node) {
                if (i.find(0) != i.end()) {
                    level0.emplace_back(i[0]);
                }
            }
            int minVal = SSSP_Dijkstra_1::INF;
            for (const int &source : level0) {
                SSSP_Dijkstra_1::dijkstra(source);
                minVal = min(minVal, SSSP_Dijkstra_1::dis.at(K));
                SSSP_Dijkstra_1::reset();
            }
            if (minVal == SSSP_Dijkstra_1::INF) {
                cout << "IMPOSSIBLE" << '\n';
            } else {
                cout << minVal << '\n';
            }
        }
        // reset
        vector<Edge>().swap(edges);
        decltype(level2node)().swap(level2node);
        node_counter = 0;
        vector<int>().swap(speed);
        vector<vector<int> >().swap(levels);
    }

    return 0;
}