class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        constexpr int STEPS = 4;
        const int dx[] = {0,0,-1,1};
        const int dy[] = {-1,1,0,0};
        
        int ans = 0;
        int n = (int)grid.size();
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ans += 2;   // top, down
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                            if (grid[new_i][new_j] < grid[i][j]) {
                                ans += grid[i][j] - grid[new_i][new_j];
                            }
                        }
                        else {
                            ans += grid[i][j];  // grid[i][j] is a boundary on this side
                        }
                    }
                }
            }
        }
        return ans;
    }
};