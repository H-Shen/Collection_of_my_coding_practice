#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr int WEIGHT = 1;
constexpr int STEPS = 4;
constexpr array<int, STEPS> dx = {0, 0, 1, -1};
constexpr array<int, STEPS> dy = {1, -1, 0, 0};

auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int n, m, original_i, original_j, dest_i, dest_j;
vector<vector<char> > M;
vector<vector<int> > dis;

void bfs() {
    dis.at(original_i).at(original_j) = 0;
    queue<pii> q;
    q.push({original_i, original_j});
    pii current;
    int new_i, new_j;
    while (!q.empty()) {
        current = q.front();
        q.pop();
        for (int step = 0; step < STEPS; ++step) {
            new_i = current.first + dx[step];
            new_j = current.second + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(new_i).at(new_j) != '#' && dis.at(new_i).at(new_j) == INF) {
                dis.at(new_i).at(new_j) = dis.at(current.first).at(current.second) + WEIGHT;
                q.push({new_i, new_j});
            }
        }
    }
}

int main() {

    fast_io();
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
        for (int j = 0; j < m; ++j) {
            if (s.at(j) == 'd') {
                dest_i = i;
                dest_j = j;
            } else if (s.at(j) == 'm') {
                original_i = i;
                original_j = j;
            }
        }
    }
    dis.resize(n, vector<int>(m, INF));
    bfs();
    if (dis.at(dest_i).at(dest_j) == INF) {
        cout << "No Way!" << '\n';
    } else {
        cout << dis.at(dest_i).at(dest_j) << '\n';
    }

    return 0;
}
