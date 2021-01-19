// https://open.kattis.com/problems/importspaghetti

#include <bits/extc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr ll INF = 0x3f3f3f3f;
constexpr int MAXN = 505;

ll n;
unordered_map<string, int> node2id;
vector<string> id2node;

namespace SSSP_Dijkstra_1 {

    vector<vector<int> > adj; // The adjacency list of the graph
    int number_of_nodes;
    vector<int> prev;   // an auxiliary container to store the path
    bitset<MAXN> vis;

    inline void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        if (store_path) {
            prev.resize(number_of_nodes + 5, -1);
        }
    }

    inline void
    add_edge(int u, int v) {
        adj.at(u).emplace_back(v);
    }

    inline ll
    dijkstra(int source, bool store_path = false) {
        vis.reset();
        bool flag = true;
        vector<ll> dis(number_of_nodes + 5, INF);
        if (store_path) {
            fill(prev.begin(), prev.end(), -1);
        }
        dis.at(source) = 0;
        std::priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int v = pq.top().second;
            pq.pop();
            if (vis[v]) {
                continue;
            }
            vis[v] = true;
            for (const auto &to : adj.at(v)) {
                if (dis.at(to) > dis.at(v) + 1) {
                    dis.at(to) = dis.at(v) + 1;
                    if (store_path) {
                        prev.at(to) = v;
                    }
                    if (!vis[to]) {
                        pq.push(make_pair(dis.at(to), to));
                    }
                }
            }
            // reset the start point
            if (flag) {
                vis[source] = false;
                dis.at(source) = INF;
                flag = false;
            }
        }
        return dis.at(source);
    }

    inline vector<int>
    get_path(int destination) {
        vector<int> path;
        unordered_set<int> unset;
        for (; destination != -1; destination = prev.at(destination)) {
            if (unset.find(destination) != unset.end()) {
                break;
            }
            unset.insert(destination);
            path.emplace_back(destination);
        }
        return path;
    }
}

vector<int> parse(const string &s) {
    const static regex r ("[a-z]+");
    bool first = true;
    vector<int> result;
    for (sregex_iterator a(s.begin(), s.end(), r), e; a != e; ++a) {
        if (first) {
            first = false;
        } else {
            result.emplace_back(node2id[a->str()]);
        }
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    SSSP_Dijkstra_1::init(n, true);

    string s;
    id2node.emplace_back("");
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        node2id[s] = i;
        id2node.emplace_back(s);
    }
    // sections
    int v, m;
    string useless;
    for (int i = 1; i <= n; ++i) {
        cin >> s >> m;
        v = node2id[s];
        cin.get();
        for (int j = 1; j <= m; ++j) {
            getline(cin, s);
            auto vec = parse(s);
            for (const auto &u : vec) {
                SSSP_Dijkstra_1::add_edge(u, v);
                // we check self-loop here, once found, exit
                if (u == v) {
                    cout << id2node[u] << '\n';
                    return 0;
                }
            }
        }
    }
    ll minimalCycle = INF;
    for (int i = 1; i <= n; ++i) {
        minimalCycle = min(minimalCycle, SSSP_Dijkstra_1::dijkstra(i, false));
    }

    if (minimalCycle == INF) {
        cout << "SHIP IT" << '\n';
    } else {
        for (int i = 1; i <= n; ++i) {
            if (SSSP_Dijkstra_1::dijkstra(i, true) == minimalCycle) {
                auto path = SSSP_Dijkstra_1::get_path(i);
                bool firstCase = true;
                for (const auto &j : path) {
                    if (firstCase) {
                        firstCase = false;
                    } else {
                        cout << ' ';
                    }
                    cout << id2node[j];
                }
                cout << '\n';
                break;
            }
        }
    }

    return 0;
}
