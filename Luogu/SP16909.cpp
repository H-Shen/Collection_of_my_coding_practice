#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace Bridges {

    constexpr int INF = 0x3f3f3f3f;
    vector<int> dfs_num;
    vector<int> dfs_low;
    vector<int> dfs_parent;
    int dfsNumberCounter;
    vector<vector<int> > adj;
    vector<pair<int, int> > bridges;

    void getBridges(int u) {
        dfs_num[u] = dfsNumberCounter;
        ++dfsNumberCounter;
        dfs_low[u] = dfs_num[u];
        for (const auto &v : adj[u]) {
            if (dfs_num[v] == INF) {
                dfs_parent[v] = u;
                getBridges(v);
                if (dfs_low[v] > dfs_num[u]) {
                    if (u > v) {
                        bridges.emplace_back(v, u);
                    } else {
                        bridges.emplace_back(u, v);
                    }
                }
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }
            else if (v != dfs_parent[u]) {
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }

    void init(int n) {
        decltype(adj)().swap(adj);
        vector<int>().swap(dfs_num);
        vector<int>().swap(dfs_low);
        vector<int>().swap(dfs_parent);
        vector<pair<int, int> >().swap(bridges);
        dfsNumberCounter = 0;

        dfs_num.resize(n + 5, INF);
        dfs_low.resize(n + 5, 0);
        dfs_parent.resize(n + 5, -1);
        adj.resize(n + 5);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nc, n, m, u, v;
    cin >> nc;
    for (int kase = 1; kase <= nc; ++kase) {
        cin >> n >> m;
        Bridges::init(n);
        while (m--) {
            cin >> u >> v;
            Bridges::adj[u].emplace_back(v);
            Bridges::adj[v].emplace_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            if (Bridges::dfs_num[i] == Bridges::INF) {
                Bridges::getBridges(i);
            }
        }
        cout << "Caso #" << kase << '\n';
        if (Bridges::bridges.empty()) {
            cout << "Sin bloqueos" << '\n';
        }
        else {
            sort(Bridges::bridges.begin(), Bridges::bridges.end());
            cout << Bridges::bridges.size() << '\n';
            for (const auto &e : Bridges::bridges) {
                cout << e.first << ' ' << e.second << '\n';
            }
        }
    }
    return 0;
}