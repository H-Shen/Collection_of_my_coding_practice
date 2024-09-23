// 最短路计数 最短路中的最大点权和

#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

vector<vector<pair<int,int> > > AL;
vector<int> weights;  // 点权
vector<int> w;   // 从s到各点的最大点权和
vector<int> cnt; // 从s到各点的最短路计数
int n, m, s, t, u, v, weight;
vector<int> dist;

void dijkstra() {
    dist.resize(n, INF);
    dist[s] = 0;
    cnt[s] = 1;
    w[s] = weights[s];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
    pq.push({dist[s],s});
    while (!pq.empty()) {
        int d_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d_u != dist[u]) continue;
        for (const auto &i : AL[u]) {
            v = i.first;
            weight = i.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v],v});
                cnt[v] = cnt[u];
                w[v] = w[u] + weights[v];
            }
            else if (dist[u] + weight == dist[v]) {
                cnt[v] += cnt[u];
                if (w[u] + weights[v] > w[v]) {
                    w[v] = w[u] + weights[v];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    weights.resize(n);
    w.resize(n);
    AL.resize(n);
    cnt.resize(n);
    for (auto &i : weights) cin >> i;
    while (m--) {
        cin >> u >> v >> weight;
        AL[u].emplace_back(v,weight);
        AL[v].emplace_back(u,weight);
    }
    dijkstra();
    cout << cnt[t] << ' ' << w[t] << '\n';
    return 0;
}
