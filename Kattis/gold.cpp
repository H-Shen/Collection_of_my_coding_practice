// https://open.kattis.com/problems/gold

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n, m, pos_x, pos_y;
vector<vector<char> > M;
vector<vector<bool> > vis;

bool closeToTrap(int i, int j) {
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        try {
            if (M.at(new_i).at(new_j) == 'T') {
                return true;
            }
        } catch (...) {}
    }
    return false;
}

void dfs(int i, int j) {
    if (closeToTrap(i, j)) {
        return;
    }
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !vis[new_i][new_j]) {
            vis[new_i][new_j] = true;
            dfs(new_i, new_j);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> n;
    vis.resize(n, vector<bool>(m, false));
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
        for (int j = 0; j < m; ++j) {
            if (s.at(j) == 'P') {
                pos_x = i;
                pos_y = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M[i][j] == '#') {
                vis[i][j] = true;
            }
        }
    }
    vis[pos_x][pos_y] = true;
    dfs(pos_x, pos_y);
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j] && M[i][j] == 'G') {
                ++counter;
            }
        }
    }
    cout << counter << '\n';

    return 0;
}
