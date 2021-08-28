constexpr int STEPS = 4;
constexpr int MAXN = 501;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int deg[MAXN][MAXN];
bitset<MAXN> vis[MAXN];
int n, m;

class Solution {
public:
    // Toposort on an undirected graph
    bool hasCycle(vector<vector<char>>& grid, vector<pair<int,int>>&res) {
        queue<pair<int,int>> q;
        for (const auto &[i,j] : res) {
            if (deg[i][j] <= 1) {
                q.push({i,j});
            }
        }
        pair<int,int> u;
        int visCounter = 0;
        int new_i,new_j;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            ++visCounter;
            for (int step = 0; step < STEPS; ++step) {
                new_i = u.first+dx[step];
                new_j = u.second+dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == grid[u.first][u.second]) {
                    --deg[new_i][new_j];
                    if (deg[new_i][new_j] == 1) {
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        return visCounter != (int)res.size();
    }
    bool bfs(vector<vector<char>>& grid, int i, int j, vector<pair<int,int>>&res) {
        vector<pair<int,int>>().swap(res);
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;
        pair<int,int> p;
        int new_i,new_j;
        while (!q.empty()) {
            p = q.front();
            res.emplace_back(p);
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                new_i = p.first+dx[step];
                new_j = p.second+dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == grid[p.first][p.second] && !vis[new_i][new_j]) {
                    vis[new_i][new_j] = true;
                    q.push({new_i,new_j});
                }
            }
        }
        return res.size() >= 4;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        for (auto &i : vis) {
            i.reset();
        }
        memset(deg, 0, sizeof deg);
        n = (int)grid.size();
        m = (int)grid[0].size();
        int new_i,new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i+dx[step];
                    new_j = j+dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == grid[i][j]) {
                        ++deg[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j]) {
                    vector<pair<int,int>> cc;
                    if (bfs(grid, i, j, cc) && hasCycle(grid, cc)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};