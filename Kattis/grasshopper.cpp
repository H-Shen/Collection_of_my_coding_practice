// https://open.kattis.com/problems/grasshopper
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 105;

bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
int r, c, g_r, g_c, l_r, l_c;

vector<pair<int, int> > transitions = {
        {1, -2},
        {1, 2},
        {-1, -2},
        {-1, 2},
        {-2, 1},
        {-2, -1},
        {2, 1},
        {2, -1}
};

void bfs(int i, int j) {
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    vis[i][j] = true;
    dis[i][j] = 0;
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (const auto &step : transitions) {
            int new_i = u.first + step.first;
            int new_j = u.second + step.second;
            if (new_i >= 1 && new_i <= r && new_j >= 1 && new_j <= c &&
                !vis[new_i][new_j] && !(i == l_r && j == l_c)) {
                q.push(make_pair(new_i, new_j));
                vis[new_i][new_j] = true;
                dis[new_i][new_j] = dis[u.first][u.second] + 1;
            }
        }
    }
}

int main() {

    while (~scanf("%d %d %d %d %d %d", &r, &c, &g_r, &g_c, &l_r, &l_c)) {
        bfs(g_r, g_c);
        if (vis[l_r][l_c]) {
            printf("%d\n", dis[l_r][l_c]);
        } else {
            printf("impossible\n");
        }
        memset(vis, 0, sizeof(bool) * MAXN * MAXN);
        memset(dis, 0, sizeof(int) * MAXN * MAXN);
    }

    return 0;
}
