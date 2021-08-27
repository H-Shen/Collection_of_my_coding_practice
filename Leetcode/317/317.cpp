constexpr int MAXN = 50;
constexpr int STEPS = 4;
constexpr int INF = 0x3f3f3f3f;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
int dist[MAXN][MAXN];   // if grid[i][j] == 1, then dist[i][j] == the sum of distances from all 0 to (i,j)
int Count[MAXN][MAXN];  // if grid[i][j] == 0, then Count[i][j] = the number of '1's that (i,j) can reach

struct Node {
    int i, j, dist;
    Node() = default;
    Node(int i, int j, int dist) : i(i), j(j), dist(dist) {}
};

class Solution {
public:
    int n, m;
    // Bfs from each 1 instead of 0 to other 0
    void bfs(vector<vector<int>> &grid, int i, int j) {
        queue<Node> q;
        bitset<MAXN> vis[MAXN];
        q.push(Node(i,j,0));
        vis[i][j] = true;
        int new_i, new_j, new_dist;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            dist[cur.i][cur.j] += cur.dist;
            for (int step = 0; step < STEPS; ++step) {
                new_i = cur.i+dx[step];
                new_j = cur.j+dy[step];
                new_dist = cur.dist+1;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != 2 && !vis[new_i][new_j]) {
                    vis[new_i][new_j] = true;
                    if (grid[new_i][new_j] == 0) {
                        ++Count[new_i][new_j];
                        q.push(Node(new_i,new_j,new_dist));
                    }
                }
            }
        }
    }
    // Check if any building cannot reach all other buildings
    bool connected(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        bitset<MAXN> vis[MAXN];
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    q.push({i,j});
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (q.empty()) {
            return false;
        }
        int new_i, new_j;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                new_i = cur.first+dx[step];
                new_j = cur.second+dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != 2 && !vis[new_i][new_j]) {
                    vis[new_i][new_j] = true;
                    if (grid[new_i][new_j] == 0) {
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        n = (int)grid.size();
        m = (int)grid[0].size();
        // Prune
        if (!connected(grid)) {
            return -1;
        }
        memset(dist, 0, sizeof dist);
        memset(Count, 0, sizeof Count);
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j);
                    ++counter;
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0 && Count[i][j] == counter) {
                    ans = min(ans, dist[i][j]);
                }
            }
        }
        return (ans == INF) ? -1 : ans;
    }
};