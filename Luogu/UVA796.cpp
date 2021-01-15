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

    void getBridge(int u) {
        dfs_num[u] = dfsNumberCounter;
        ++dfsNumberCounter;
        dfs_low[u] = dfs_num[u];
        for (const auto &v : adj[u]) {
            if (dfs_num[v] == INF) {
                dfs_parent[v] = u;
                getBridge(v);
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

    int n, u, m, v;
    while (~scanf("%d", &n)) {
        Bridges::init(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d (%d)", &u, &m);
            while (m--) {
                scanf("%d", &v);
                Bridges::adj[u].emplace_back(v);
                Bridges::adj[v].emplace_back(u);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (Bridges::dfs_num[i] == Bridges::INF) {
                Bridges::getBridge(i);
            }
        }
        printf("%d critical links\n", (int)Bridges::bridges.size());
        if (!Bridges::bridges.empty()) {
            sort(Bridges::bridges.begin(), Bridges::bridges.end());
            for (const auto &e : Bridges::bridges) {
                printf("%d - %d\n", e.first, e.second);
            }
        }
        printf("\n");
    }
    return 0;
}