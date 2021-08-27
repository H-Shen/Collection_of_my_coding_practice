class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        constexpr int INF = 0x3f3f3f3f;
        constexpr int STEPS = 8;
        const int dx[] = {-1,1,0,0,-1,1,1,-1};
        const int dy[] = {0,0,-1,1,1,-1,1,-1};
        
        int n = (int)grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        // bfs
        queue<pair<int, int> > q;
        int dist[n][n];
        
        memset(dist, 0x3f, sizeof dist);
        dist[0][0] = 1; // as long as a cell C_i exists, k >= 1
        
        q.push({0, 0});
        pair<int, int> curr;
        int new_i, new_j;
        while (!q.empty()) {
            curr = q.front();
            if (curr.first == n - 1 && curr.second == n - 1) {
                break;
            }
            q.pop();
            for (int i = 0; i < STEPS; ++i) {
                new_i = curr.first + dx[i];
                new_j = curr.second + dy[i];
                if (new_i >= 0 && 
                    new_i < n && 
                    new_j >= 0 && 
                    new_j < n && 
                    grid[new_i][new_j] == 0 &&
                    dist[new_i][new_j] == INF) {
                    q.push({new_i, new_j});
                    dist[new_i][new_j] = dist[curr.first][curr.second] + 1;
                }
            }
        }
        // output
        if (dist[n - 1][n - 1] == INF) return -1;
        return dist[n - 1][n - 1];
    }
};