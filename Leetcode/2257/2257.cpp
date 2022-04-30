class Solution {
public:
    void expand(vector<vector<int>>& vis, int n, int m, int i, int j) {
        int new_i, new_j;
        // up
        new_i = i-1;
        new_j = j;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && vis[new_i][new_j] != -1) {
            vis[new_i][new_j] = 1;
            --new_i;
        }
        // down
        new_i = i+1;
        new_j = j;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && vis[new_i][new_j] != -1) {
            vis[new_i][new_j] = 1;
            ++new_i;
        }
        
        // left
        new_i = i;
        new_j = j-1;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && vis[new_i][new_j] != -1) {
            vis[new_i][new_j] = 1;
            --new_j;
        }
        
        // right
        new_i = i;
        new_j = j+1;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && vis[new_i][new_j] != -1) {
            vis[new_i][new_j] = 1;
            ++new_j;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));  // -1: walls or guards 1: visited
        for (auto&i : guards) {
            vis[i[0]][i[1]] = -1;
        }
        for (auto&i : walls) {
            vis[i[0]][i[1]] = -1;
        }
        for (auto&i : guards) {
            expand(vis, m, n, i[0], i[1]);
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j] == 0) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};