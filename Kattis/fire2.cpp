// https://open.kattis.com/problems/fire2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr char REACH = '@';
constexpr char FIRE = '*';
constexpr char ROOM = '.';
constexpr int STEPS = 4;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

queue<pii> A, B;
int n, m, minimal_time;
vector<vector<char> > M;

void dfs(int current_time) {
    int length = static_cast<int>(A.size());
    for (int i = 0; i < length; ++i) {
        int cur_i = A.front().first;
        int cur_j = A.front().second;
        A.pop();
        // Reach the fire, skip it
        if (M.at(cur_i).at(cur_j) == FIRE) {
            continue;
        }
        // Reach a valid boundary, stop dfs, since it is the exit
        if (cur_i == 0 || cur_j == 0 || cur_i == n - 1 || cur_j == m - 1) {
            minimal_time = current_time;
            return;
        }
        int new_i, new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = cur_i + dx[step];
            new_j = cur_j + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(new_i).at(new_j) == ROOM) {
                M.at(new_i).at(new_j) = REACH;
                A.push({new_i, new_j});
            }
        }
    }
    // Case 1: no more rooms
    if (A.empty()) return;
    // Case 2: still have some rooms
    length = static_cast<int>(B.size());
    for (int i = 0; i < length; ++i) {
        int cur_i = B.front().first;
        int cur_j = B.front().second;
        B.pop();
        int new_i, new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = cur_i + dx[step];
            new_j = cur_j + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && (M.at(new_i).at(new_j) == ROOM || M.at(new_i).at(new_j) == REACH)) {
                M.at(new_i).at(new_j) = FIRE;
                B.push({new_i, new_j});
            }
        }
    }
    dfs(current_time + 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    string s;
    while (t--) {
        // reset
        minimal_time = INF;
        queue<pii>().swap(A);
        queue<pii>().swap(B);
        decltype(M)().swap(M);
        // input
        cin >> m >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            M.emplace_back(s.begin(), s.end());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M.at(i).at(j) == REACH) {
                    A.push({i, j});
                } else if (M.at(i).at(j) == FIRE) {
                    B.push({i, j});
                }
            }
        }
        dfs(1);
        if (minimal_time == INF) {
            cout << "IMPOSSIBLE";
        } else {
            cout << minimal_time;
        }
        cout << '\n';
    }
    return 0;
}
