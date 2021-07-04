class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        constexpr int INF = 0x3f3f3f3f;
        constexpr int STEPS = 4;
        const int dx[] = {1,-1,0,0};
        const int dy[] = {0,0,-1,1};
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        vector<vector<int> > dist(n, vector<int>(m, INF));
        queue<pair<int,int> > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int i, j, new_i, new_j;
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                new_i = i+dx[step];
                new_j = j+dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && dist[new_i][new_j] == INF) {
                    dist[new_i][new_j] = dist[i][j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
        return dist;
    }
};