#include <bits/stdc++.h>

using namespace std;

int n, m, k, u, v, val;
vector<vector<int> > AL;
vector<int> topo;

bool istopo() {
    // check all edges
    for (u = 1; u <= n; ++u) {
        for (const auto &v : AL[u]) {
            if (topo[u] > topo[v]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    AL.resize(n+1);
    topo.resize(n+1);
    while (m--) {
        cin >> u >> v;
        AL[u].emplace_back(v);
    }
    cin >> k;
    bool firstItem = true;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> val;
            topo[val] = j;
        }
        if (!istopo()) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
    }
    cout << '\n';
    
    return 0;
}
