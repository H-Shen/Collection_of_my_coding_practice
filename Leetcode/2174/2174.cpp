class Solution {
public:
    int ans,n,m;
    void dfs(int i, int j, vector<vector<int>> status, int counter, int moves) {
        for (int i_ = 0; i_ < n; ++i_) {
            if (status[i_][j] == 1) {
                status[i_][j] = 0;
                --counter;
            }
        }
        for (int j_ = 0; j_ < m; ++j_) {
            if (status[i][j_] == 1) {
                status[i][j_] = 0;
                --counter;
            }
        }
        if (counter == 0) {
            ans = min(ans, moves);
            return;
        }
        for (int i_ = 0; i_ < n; ++i_) {
            for (int j_ = 0; j_ < m; ++j_) {
                if (status[i_][j_] == 1) {
                    dfs(i_,j_,status,counter,moves+1);
                }
            }
        }
    }
    int removeOnes(vector<vector<int>>& grid) {
        ans = numeric_limits<int>::max();
        n = (int)grid.size();
        m = (int)grid[0].size();
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++counter;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i,j,grid,counter,1);
                }
            }
        }
        return (ans == numeric_limits<int>::max()) ? 0 : ans;
    }
};