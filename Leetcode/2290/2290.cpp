constexpr int STEPS = 4;
constexpr int MAXN = 1e5+5;
constexpr int INF = 0x3f3f3f3f;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n,m;
int dist[MAXN];

void bfs(const vector<vector<int>>& grid) {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    deque<int> dq;
    dq.push_front(0);
    int u, v, w;
    int i, j, new_i, new_j;
    while (!dq.empty()) {
        u = dq.front();
        dq.pop_front();
        i = u / m;
        j = u % m;
        for (int step = 0; step < STEPS; ++step) {
            new_i = i + dx[step];
            new_j = j + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                v = new_i*m + new_j;
                w = grid[new_i][new_j];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    if (w == 0) {
                        dq.push_front(v);
                    }
                    else {
                        dq.push_back(v);
                    }
                }
            }
        }
    }
}

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n = (int)grid.size();
        m = (int)grid[0].size();
        bfs(grid);
        return dist[n*m-1];
    }
};