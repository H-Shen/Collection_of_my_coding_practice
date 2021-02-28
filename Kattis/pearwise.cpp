// https://open.kattis.com/problems/pearwise

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 30;

int n, m, p;
vector<vector<int> > strongValue;
bitset<MAXN> vis;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int i = 0; i < n; ++i) {
        if (strongValue[u][i] > strongValue[i][u]) {
            dfs(i);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    strongValue.resize(n, vector<int>(n, 0));
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> p >> s;
        for (int j = 0; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                strongValue.at(s.at(j) - 'A').at(s.at(k) - 'A') += p;
            }
        }
    }
    bool have_ans;
    for (int i = 0; i < n; ++i) {
        have_ans = true;
        vis.reset();
        dfs(i);
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                have_ans = false;
                break;
            }
        }
        if (have_ans) {
            cout << (char)(i + 'A') << ": can win" << '\n';
        } else {
            cout << (char)(i + 'A') << ": can't win" << '\n';
        }
    }

    return 0;
}
