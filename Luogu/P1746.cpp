// An example using BFS on the shortest path
// unlike CF617A.cpp, we use 'dis' array and pair<int, int> here
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int INF = 0x3f3f3f3f;
constexpr int DIRECTIONS = 4;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

int n;
int origin_i, origin_j, dest_i, dest_j;
vector<vector<char> > M;
vector<vector<int> > dis;

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(origin_i, origin_j));
    dis.at(origin_i).at(origin_j) = 0;
    while (!q.empty()) {
        pair<int, int> current_pos = q.front();
        q.pop();
        // Reach the destination, quit the loop
        if (current_pos.first == dest_i && current_pos.second == dest_j) {
            break;
        }
        // Iterate four directions
        int new_i;
        int new_j;
        for (int step = 0; step < DIRECTIONS; ++step) {
            new_i = current_pos.first + di[step];
            new_j = current_pos.second + dj[step];
            // 1. check if the range is valid
            // 2. check if the current position is an obstacle
            // 3. check if the current position is visited
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
                M.at(new_i).at(new_j) == '0' &&
                dis.at(new_i).at(new_j) == INF) {
                q.push(make_pair(new_i, new_j));
                // update the current distance
                dis.at(new_i).at(new_j) =
                        dis.at(current_pos.first).at(current_pos.second) + 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    dis.resize(n, vector<int>(n, INF));
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    cin >> origin_i >> origin_j >> dest_i >> dest_j;
    --origin_i;
    --origin_j;
    --dest_i;
    --dest_j;
    bfs();
    cout << dis.at(dest_i).at(dest_j) << '\n';

    return 0;
}
