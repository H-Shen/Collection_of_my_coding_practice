#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 105;

vector<vector<int> > AL;
vector<vector<int> > levelorder;

int getHeight(int u, int fa) {
    int height = 0;
    for (const auto &v : AL[u]) {
        if (v == fa) continue;
        height = max(height, 1+getHeight(v,u));
    }
    return height;
}

void bfs() {
    queue<pair<int,int> > q;
    q.push({1,0});
    bitset<MAXN> vis;
    int u, currLevel;
    while (!q.empty()) {
        u = q.front().first;
        currLevel = q.front().second;
        vis[u] = true;
        levelorder[currLevel].emplace_back(u);
        q.pop();
        for (const auto &v : AL[u]) {
            if (!vis[v]) {
                q.push({v,currLevel+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, c, u, v;
    string s;
    cin >> n >> m;
    AL.resize(n+1);
    while (m--) {
        cin >> s;
        u = stoi(s);
        cin >> c;
        while (c--) {
            cin >> s;
            v = stoi(s);
            AL[u].emplace_back(v);
            AL[v].emplace_back(u);
        }
    }
    levelorder.resize(getHeight(1,-1)+1);
    bfs();
    size_t maxSize = 0;
    for (const auto &i : levelorder) {
        maxSize = max(maxSize, i.size());
    }
    for (size_t i = 0; i != levelorder.size(); ++i) {
        if (levelorder[i].size() == maxSize) {
            cout << maxSize << ' ' << i+1 << '\n';
            break;
        }
    }
    return 0;
}
