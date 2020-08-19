#include <bits/stdc++.h>

using namespace std;

namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source

    inline void
    init(int n) {
        number_of_nodes = n;
        // clean the containers
        decltype(adj)().swap(adj);
        decltype(dis)().swap(dis);
        // initialize the containers
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
    dijkstra() {
        dis.at(source) = 0;
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
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
    }
}

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    fast_io();
    int s, n, p, nr, cost, q, u, v;
    string city_name, city_u, city_v;
    cin >> s;
    while (s--) {
        cin >> n;
        SSSP_Dijkstra_1::init(n);
        unordered_map<string, int> name2id;
        for (int i = 1; i <= n; ++i) {
            cin >> city_name;
            name2id[city_name] = i;
            cin >> p;
            while (p--) {
                cin >> nr >> cost;
                SSSP_Dijkstra_1::add_edge(i, nr, cost);
            }
        }
        // query
        cin >> q;
        while (q--) {
            cin >> city_u >> city_v;
            u = name2id[city_u];
            v = name2id[city_v];
            SSSP_Dijkstra_1::source = u;
            SSSP_Dijkstra_1::dijkstra();
            cout << SSSP_Dijkstra_1::dis.at(v) << '\n';
            SSSP_Dijkstra_1::reset();
        }
    }

    return 0;
}