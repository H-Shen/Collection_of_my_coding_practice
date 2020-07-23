// An example that uses BFS to get the shortest path from a single source
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAX_SIZE = 405;
constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
constexpr int STEPS = 8;
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, -1, 1, -1, 1};

bitset<MAX_SIZE> vis[MAX_SIZE];
vector<vector<int> > dis;
int n, m, origin_i, origin_j;

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(origin_i, origin_j));
    dis.at(origin_i).at(origin_j) = 0;
    while (!q.empty()) {
        pair<int, int> current_pos = q.front();
        q.pop();
        // Iterate eight steps
        int new_i;
        int new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = current_pos.first + dx[step];
            new_j = current_pos.second + dy[step];
            // 1. check if the range is valid
            // 2. check if the current position is visited
            if (new_i >= 1 && new_i <= n && new_j >= 1 && new_j <= m && dis.at(new_i).at(new_j) == INF) {
                q.push(make_pair(new_i, new_j));
                // update the current distance
                dis.at(new_i).at(new_j) =
                        dis.at(current_pos.first).at(current_pos.second) + 1;
            }
        }
    }
}

int main() {

    scanf("%d %d %d %d", &n, &m, &origin_i, &origin_j);
    dis.resize(n + 5, vector<int>(m + 5, INF));
    bfs();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dis.at(i).at(j) == INF) {
                printf("%-5d", -1);
            } else {
                printf("%-5d", dis.at(i).at(j));
            }
        }
        printf("\n");
    }


    return 0;
}
