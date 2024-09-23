// 最短路树生成 双边权处理

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int v, w, c;
    Node() = default;
    Node(int v, int w, int c) : v(v), w(w), c(c) {}
};

namespace ShortestPathTree {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<Node> > AL;
    int s, n;
    vector<int> dist;
    vector<vector<pair<int,int> > > spt;
    void dijkstra() {
        dist.resize(n, INF);
        dist[s] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
        pq.push({dist[s],s});
        while (!pq.empty()) {
            int d_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d_u != dist[u]) continue;
            for (const auto &i : AL[u]) {
                int v = i.v;
                int w = i.w;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    void getSPT() {
        spt.resize(n);
        for (int i = 0; i < n; ++i) {
            for (const auto &j : AL[i]) {
                if (dist[i] + j.w == dist[j.v]) {
                    spt[i].emplace_back(j.v, j.c);
                }
            }
        }
    }
    // run Dijkstra again on SPT
    vector<int> dist2;
    vector<int> prev;
    void dijkstra2() {
        dist2.resize(n, INF);
        prev.resize(n, -1);
        dist2[s] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
        pq.push({dist2[s],s});
        while (!pq.empty()) {
            int d_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d_u != dist2[u]) continue;
            for (const auto &i : spt[u]) {
                int v = i.first;
                int w = i.second;
                if (dist2[u] + w < dist2[v]) {
                    dist2[v] = dist2[u] + w;
                    pq.push({dist2[v],v});
                    prev[v] = u;
                }
            }
        }
    }
    vector<int> getPath(int dest) {
        vector<int> ans;
        for (; dest != -1; dest = prev[dest]) {
            ans.emplace_back(dest);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
}

int n, m, s, t, u, v, w, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    ShortestPathTree::AL.resize(n);
    ShortestPathTree::n = n;
    ShortestPathTree::s = s;
    while (m--) {
        cin >> u >> v >> w >> c;
        ShortestPathTree::AL[u].emplace_back(Node(v,w,c));
        ShortestPathTree::AL[v].emplace_back(Node(u,w,c));
    }
    ShortestPathTree::dijkstra();
    ShortestPathTree::getSPT();
    ShortestPathTree::dijkstra2();
    auto p = ShortestPathTree::getPath(t);
    for (const auto &i : p) {
        cout << i << ' ';
    }
    cout << ShortestPathTree::dist[t] << ' ' << ShortestPathTree::dist2[t] << '\n';
    return 0;
}
