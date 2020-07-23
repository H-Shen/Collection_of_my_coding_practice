#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace SSSP_SPFA {

    constexpr int MAX_NODES = 1005;
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    init(int n, int s) {
        vector<vector<pair<int, int> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, -INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    bitset<MAX_NODES> in_queue;
    inline bool
    spfa() {
        vector<int> cnt(number_of_nodes + 5);
        queue<int> q;
        q.push(source);
        in_queue[source] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (const auto &[v, w] : adj.at(u)) {
                if (dis.at(v) < dis.at(u) + w) {
                    dis.at(v) = dis.at(u) + w;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                        ++cnt.at(v);
                        if (cnt.at(v) > number_of_nodes) {
                            return false;   // a negative cycle exists
                        }
                    }
                }
            }
        }
        return true;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, u, v;
    cin >> n;
    string s;
    cin >> s;
    SSSP_SPFA::init(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        u = i + 1;
        v = i + 2;
        if (s.at(i) == 'L') {
            SSSP_SPFA::add_edge(v, u, 1);
        } else if (s.at(i) == 'R') {
            SSSP_SPFA::add_edge(u, v, 1);
        } else {
            SSSP_SPFA::add_edge(u, v, 0);
            SSSP_SPFA::add_edge(v, u, 0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        SSSP_SPFA::add_edge(n + 1, i, 1);
    }
    for (int i = 1; i <= n + 1; ++i) {
        SSSP_SPFA::add_edge(0, i, 0);
    }
    SSSP_SPFA::spfa();
    bool first_item = true;
    for (int i = 1; i <= n; ++i) {
        if (first_item) {
            first_item = false;
        } else {
            cout << ' ';
        }
        cout << SSSP_SPFA::dis.at(i);
    }
    cout << '\n';
    return 0;
}