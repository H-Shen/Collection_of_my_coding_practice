// https://open.kattis.com/problems/bryr

#include <bits/extc++.h>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

int n, m;
vector<vector<pair<int, int> > > adj;
vector<int> dist;

void bfs() {
    deque<int> q;
    q.push_back(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (const auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 5);
    dist.resize(n + 5, INF);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    bfs();
    cout << dist[n] << '\n';


    return 0;
}
