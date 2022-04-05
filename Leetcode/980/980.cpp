constexpr int STEPS = 4;
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

class Solution {
public:
    int n, m, cnt;
    int non_obs;
    void dfs(vector<vector<int>>& grid, vector<vector<int>> vis, int cur_i, int cur_j, int target_i, int target_j, int steps) {
        if (cur_i == target_i && cur_j == target_j && steps == non_obs) {
            ++cnt;
            return;
        }
        int new_i, new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = cur_i + dx[step];
            new_j = cur_j + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != -1 && vis[new_i][new_j] == 0) {
                // 写成回溯形式的时候 vis写在循环中
                vis[new_i][new_j] = 1;
                dfs(grid, vis, new_i, new_j, target_i, target_j, steps + 1);
                vis[new_i][new_j] = 0;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = (int)grid.size();
        m = (int)grid[0].size();
        cnt = 0;
        non_obs = 0;
        int start_i, start_j, end_i, end_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
                if (grid[i][j] == 2) {
                    end_i = i;
                    end_j = j;
                }
                if (grid[i][j] != -1) {
                    ++non_obs;
                }
            }
        }
        vector<vector<int>> vis(n, vector<int>(m));
        vis[start_i][start_j] = true;
        dfs(grid, vis, start_i, start_j, end_i, end_j, 1);
        return cnt;
    }
};