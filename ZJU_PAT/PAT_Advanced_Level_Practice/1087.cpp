#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 205;

int n, k, s, t, id;
double maxAvgWeight = 0.0;
unordered_map<string,int> name2id;
vector<string> id2name;
vector<int> weights;
vector<int> ways;
vector<vector<pair<int,int> > > AL;
vector<int> W;
vector<int> dist;
vector<vector<pair<int,int> > > spt;

void getSpt() {
    spt.resize(n);
    for (int i = 0; i < n; ++i) {
        for (const auto &j : AL[i]) {
            if (dist[i] + j.second == dist[j.first]) {
                spt[i].emplace_back(j.first, j.second);
            }
        }
    }
}

void dfs(int u, bitset<MAXN> vis, int nodesVisited, int weight) {
    if (u == t && weight == W[t]) {
        maxAvgWeight = max(maxAvgWeight, weight * 1.0 / nodesVisited);
        return;
    }
    for (const auto &i : spt[u]) {
        int v = i.first;
        if (!vis[v]) {
            vis[v] = true;
            dfs(v, vis, nodesVisited+1, weight+weights[v]);
            vis[v] = false;
        }
    }
}

vector<int> ans;
void dfs2(int u, bitset<MAXN> vis, int nodesVisited, int weight, vector<int> path) {
    if (u == t && weight == W[t]) {
        if (nodesVisited > 0 && weight * 1.0 / nodesVisited == maxAvgWeight) {
            ans = path;
            return;
        }
    }
    for (const auto &i : spt[u]) {
        int v = i.first;
        if (!vis[v]) {
            vis[v] = true;
            path.emplace_back(v);
            dfs2(v, vis, nodesVisited+1, weight+weights[v], path);
            vis[v] = false;
            path.pop_back();
        }
    }
}

void dijkstra() {
    dist.resize(n,INF);
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
    pq.push({dist[s],s});
    ways[s] = 1;
    while (!pq.empty()) {
        int d_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d_u != dist[u]) continue;
        for (const auto &i : AL[u]) {
            int v = i.first;
            int w = i.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                W[v] = W[u] + weights[v];
                ways[v] = ways[u];
                pq.push({dist[v],v});
            }
            else if (dist[v] == dist[u] + w) {
                W[v] = max(W[v], W[u] + weights[v]);
                ways[v] += ways[u];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    cin >> n >> k >> str;
    AL.resize(n);
    weights.resize(n);
    W.resize(n);
    ways.resize(n);
    name2id[str] = id;
    s = id;
    ++id;
    id2name.emplace_back(str);
    int cost;
    for (int i = 0; i < n - 1; ++i) {
        cin >> str >> cost;
        name2id[str] = id;
        weights[id] = cost;
        id2name.emplace_back(str);
        ++id;
    }
    t = name2id["ROM"];
    int u, v, w;
    for (int i = 0; i < k; ++i) {
        cin >> str;
        u = name2id[str];
        cin >> str;
        v = name2id[str];
        cin >> w;
        AL[u].emplace_back(v,w);
        AL[v].emplace_back(u,w);
    }
    dijkstra();
    getSpt();
    bitset<MAXN> bs;
    bs[s] = true;
    dfs(s, bs, 0, weights[s]);
    vector<int> p;
    p.emplace_back(s);
    dfs2(s, bs, 0, weights[s], p);
    cout << ways[t] << ' ' << dist[t] << ' ' << W[t] << ' ' << (int)maxAvgWeight << '\n';
    bool firstItem = true;
    for (const auto &i : ans) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << "->";
        }
        cout << id2name[i];
    }
    cout << '\n';
    return 0;
}
