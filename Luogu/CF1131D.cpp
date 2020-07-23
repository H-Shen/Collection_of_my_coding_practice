#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace SSSP_SPFA {
    constexpr int MAX_NODES = 2005;
    constexpr ll INF = 0x3f3f3f3f3f;
    vector<vector<pair<int, ll> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<ll> dis;

    inline void
    init(int n, int s) {
        vector<vector<pair<int, ll> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, ll w) {
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
                if (dis.at(v) > dis.at(u) + w) {
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

vector<vector<char> > R;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, u, v;
    string temp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        R.emplace_back(temp.begin(), temp.end());
    }
    SSSP_SPFA::init(n + m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            u = i + 1;
            v = n + j + 1;
            // u < v -> u - v < 0 -> u - v <= -1
            if (R.at(i).at(j) == '<') {
                SSSP_SPFA::add_edge(v, u, -1);
            }
            // u > v -> u - v > 0 -> v - u < 0 -> v - u <= -1
            else if (R.at(i).at(j) == '>') {
                SSSP_SPFA::add_edge(u, v, -1);
            }
            // u = v -> u - v >= 0 && u - v <= 0 -> v - u <= 0 && u - v <= 0
            else {
                SSSP_SPFA::add_edge(u, v, 0);
                SSSP_SPFA::add_edge(v, u, 0);
            }
        }
    }
    for (int i = 1; i <= n + m; ++i) {
        SSSP_SPFA::add_edge(0, i, 0);
    }
    if (SSSP_SPFA::spfa()) {
        for (int i = 1; i <= n + m; ++i) {
            if (SSSP_SPFA::dis.at(i) == SSSP_SPFA::INF) {
                cout << "No" << '\n';
                return 0;
            }
        }
        cout << "Yes" << '\n';
        bool first_item = true;
        ll min_val = numeric_limits<ll>::max();
        ll diff = 0;
        for (int i = 1; i <= n + m; ++i) {
            min_val = min(min_val, SSSP_SPFA::dis.at(i));
        }
        if (min_val <= 0) {
            diff = -min_val + 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (first_item) {
                first_item = false;
            } else {
                cout << ' ';
            }
            cout << SSSP_SPFA::dis.at(i) + diff;
        }
        cout << '\n';
        first_item = true;
        for (int i = n + 1; i <= n + m; ++i) {
            if (first_item) {
                first_item = false;
            } else {
                cout << ' ';
            }
            cout << SSSP_SPFA::dis.at(i) + diff;
        }
        cout << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}