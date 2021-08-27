constexpr int STEPS = 4;
constexpr int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

class Solution {
public:
    queue<pair<int, int> > q;
    vector<vector<int> > dist;
    void bfs(int n) {
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int new_i, new_j;
            for (int step = 0; step < STEPS; ++step) {
                new_i = cur.first + dx[step];
                new_j = cur.second + dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && dist[new_i][new_j] == INF) {
                    dist[new_i][new_j] = dist[cur.first][cur.second] + 1;
                    q.push({new_i, new_j});
                }
            }
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        dist.resize(n, vector<int>(n, INF));
        bool containsZero = false;
        bool containsOne = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    containsZero = true;
                } else if (grid[i][j] == 1) {
                    containsOne = true;
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        if (!containsZero || !containsOne) {
            return -1;
        }
        bfs(n);
        int maxDist = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    maxDist = max(maxDist, dist[i][j]);
                }
            }
        }
        return maxDist;
    }
};