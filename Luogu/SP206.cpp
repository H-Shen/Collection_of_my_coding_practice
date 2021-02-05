#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

constexpr int STEPS = 4;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
vector<vector<char> > M;
vector<vector<int> > dist;
queue<ii> q;

void bfs() {
    while (!q.empty()) {
        ii cur = q.front();
        q.pop();
        int new_i, new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = cur.first + dx[step];
            new_j = cur.second + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && dist[new_i][new_j] == -1) {
                dist[new_i][new_j] = dist[cur.first][cur.second] + 1;
                q.push({new_i, new_j});
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> n >> m;
        decltype(M)().swap(M);
        decltype(q)().swap(q);
        decltype(dist)().swap(dist);
        dist.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            cin >> s;
            M.emplace_back(s.begin(), s.end());
            for (int j = 0; j < m; ++j) {
                if (M.at(i).at(j) == '1') {
                    q.push({i, j});
                    dist.at(i).at(j) = 0;
                }
            }
        }
        bfs();
        for (int i = 0; i < n; ++i) {
            cout << dist.at(i).at(0);
            for (int j = 1; j < m; ++j) {
                cout << ' ' << dist.at(i).at(j);
            }
            cout << '\n';
        }
    }


    return 0;
}