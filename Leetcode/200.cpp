class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        constexpr int MAXN = 305;
        constexpr int STEPS = 4;
        constexpr int dx[] = {0, 0, 1, -1};
        constexpr int dy[] = {1, -1, 0, 0};
        bitset<MAXN> vis[MAXN];
        int n = (int)grid.size();
        int m = (int)grid.front().size();
        auto bfs = [&](const pair<int, int> &u){
            queue<pair<int, int> > q;
            q.push(u);
            vis[u.first][u.second] = true;
            pair<int, int> cur;
            int new_i, new_j;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                for (int step = 0; step < STEPS; ++step) {
                    new_i = cur.first + dx[step];
                    new_j = cur.second + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !vis[new_i][new_j] && grid[new_i][new_j] == '1') {
                        vis[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
        };
        int regions = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ++regions;
                    bfs({i, j});
                }
            }
        }
        return regions;
    }
};