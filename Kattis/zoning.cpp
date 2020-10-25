// https://open.kattis.com/problems/zoning
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 1505;
constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, 1, -1, 0};

vector<vector<char> > M;
vector<vector<int> > dis;
bitset<MAXN> vis[MAXN];

int r, c;
int answer = -INF;
vector<pii> residents;

void bfs() {
    queue<pii> q;
    for (const auto &i : residents) {
        q.push({i.first, i.second});
        vis[i.first][i.second] = true;
        dis.at(i.first).at(i.second) = 0;
    }
    pii u;
    int new_i, new_j;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int step = 0; step < STEPS; ++step) {
            new_i = u.first + di[step];
            new_j = u.second + dj[step];
            if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
                // Do some update no matter it is visited or not
                if (dis.at(new_i).at(new_j) > dis.at(u.first).at(u.second) + 1) {
                    dis.at(new_i).at(new_j) = dis.at(u.first).at(u.second) + 1;
                }
                // If not visited, add to the queue
                if (!vis[new_i][new_j]) {
                    vis[new_i][new_j] = true;
                    q.push({new_i, new_j});
                    // Update the answer only if it is visited
                    if (M.at(new_i).at(new_j) == '1') {
                        answer = max(answer, dis.at(new_i).at(new_j));
                    }
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> r;
    c = r;
    dis.resize(r, vector<int>(c, INF));
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
        for (int j = 0; j < c; ++j) {
            if (M.at(i).at(j) == '3') {
                residents.emplace_back(i, j);
            }
         }
    }
    bfs();
    cout << answer << '\n';

    return 0;
}
