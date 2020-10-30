class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        constexpr int dx[] = {1, -1, 0, 0};
        constexpr int dy[] = {0, 0, -1, 1};
        constexpr int STEPS = 4;
        int counter = 0;
        int n = (int)grid.size();
        int m = (int)grid.front().size();
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || !grid[new_i][new_j]) {
                            ++counter;
                        }
                    }
                }
            }
        }
        return counter;
    }
};