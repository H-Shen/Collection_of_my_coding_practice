class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        // bfs
        constexpr int INF = 0x3f3f3f3f;
        constexpr int STEPS = 4;
        int dx[] = {0,0,1,-1};
        int dy[] = {-1,1,0,0};
        
        int n = (int)grid.size();
        int m = (int)grid.front().size();
        vector<vector<int> > dist(n, vector<int>(m, INF));
        vector<pair<int,int> > dest;
        queue<pair<int,int> > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                else if (grid[i][j] == '#') {
                    dest.emplace_back(i,j);
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (grid[i][j] == '#') {
                return dist[i][j];
            } 
            int new_i, new_j;
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != 'X' && dist[new_i][new_j] == INF) {
                    dist[new_i][new_j] = dist[i][j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
        return -1;
    }
};