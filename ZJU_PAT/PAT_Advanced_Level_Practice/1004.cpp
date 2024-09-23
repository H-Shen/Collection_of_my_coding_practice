#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 105;

vector<vector<int> > AL;
bitset<MAXN> outDegree;
vector<vector<int> > level;
int n, m, height;

int getHeight(int u, int fa) {
    if (AL[u].empty()) {
        return 0;
    }
    int ans = 0;
    for (const auto &v : AL[u]) {
        if (v != fa) {
            ans = max(ans, 1+getHeight(v,u));
        }
    }
    return ans;
}

void bfs() {
    queue<pair<int,int> > q;
    bitset<MAXN> vis;
    q.push(make_pair(1,0));
    int u, currLevel;
    while (!q.empty()) {
        u = q.front().first;
        currLevel = q.front().second;
        level[currLevel].emplace_back(u);
        vis[u] = true;
        q.pop();
        for (const auto &v : AL[u]) {
            if (!vis[v]) {
                q.push(make_pair(v,currLevel+1));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        if (!(cin >> n) || n == 0) break;
        decltype(AL)().swap(AL);
        outDegree.reset();
        AL.resize(n+1);
        cin >> m;
        int u, k, v;
        string s;
        for (int i = 0; i < m; ++i) {
            cin >> s;
            u = stoi(s);
            cin >> k;
            outDegree[u] = true;
            while (k--) {
                cin >> s;
                v = stoi(s);
                AL[u].emplace_back(v);
                AL[v].emplace_back(u);
            }
        }
        height = getHeight(1, -1);
        decltype(level)().swap(level);
        level.resize(height+1);
        bfs();
        int counter;
        bool firstItem = true;
        for (const auto &i : level) {
            counter = 0;
            for (const auto &j : i) {
                if (!outDegree[j]) {
                    ++counter;
                }
            }
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << counter;
        }
        cout << '\n';
    }
    return 0;
}
