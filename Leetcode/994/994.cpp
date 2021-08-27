constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        queue<pair<int,int> > q;
        vector<pair<int,int> > v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 0) {
                    grid[i][j] = -1;
                }
                else {
                    grid[i][j] = INF;
                    v.emplace_back(i,j);
                }
            }
        }
        // Case 1:
        if (v.empty()) return 0;
        int i, j, new_i, new_j;
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == INF) {
                    grid[new_i][new_j] = grid[i][j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
        int ans = 0;
        for (const auto &[r,c] : v) {
            // Case 2:
            if (grid[r][c] == INF) {
                return -1;
            }
            ans = max(ans, grid[r][c]);
        }
        // Case 3:
        return ans;
    }
};