#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 8;

vector<pair<int, int> > transitions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
};
int r, c, origin_i, origin_j, dest_i, dest_j;
bool vis[MAXN][MAXN];
bool obstacle[MAXN][MAXN];
int ways = 0;

void dfs(int i, int j) {
    if (i == dest_i && j == dest_j) {
        ++ways;
        return;
    }
    int new_i, new_j;
    for (const auto &step : transitions) {
        new_i = i + step.first;
        new_j = j + step.second;
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
            if (!vis[new_i][new_j] && !obstacle[new_i][new_j]) {
                vis[new_i][new_j] = true;
                dfs(new_i, new_j);
                vis[new_i][new_j] = false;  // backtracing
            }
        }
    }
}

int main() {

    int t, obstacle_i, obstacle_j;
    scanf("%d %d %d", &r, &c, &t);
    scanf("%d %d %d %d", &origin_i, &origin_j, &dest_i, &dest_j);
    --origin_i;
    --origin_j;
    --dest_i;
    --dest_j;
    while (t--) {
        scanf("%d %d", &obstacle_i, &obstacle_j);
        --obstacle_i;
        --obstacle_j;
        obstacle[obstacle_i][obstacle_j] = true;
    }
    vis[origin_i][origin_j] = true;
    dfs(origin_i, origin_j);
    printf("%d\n", ways);

    return 0;
}