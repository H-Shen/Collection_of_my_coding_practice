namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x,y);
        father[x] = y;
        Size[y] += Size[x];
    }
}

constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        DSU::init(n*m);
        int new_i,new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i+dx[step];
                        new_j = j+dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1) {
                            DSU::merge(i*m+j,new_i*m+new_j);
                        }
                    }
                }
            }
        }
        unordered_map<int,vector<int> > unmap;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    unmap[DSU::find(i*m+j)].emplace_back(i*m+j);
                }
            }
        }
        auto &group = unmap.begin()->second;
        for (const auto &pos : group) {
            grid[pos/m][pos%m] = 2;
        }
        // multiple bfs
        vector<vector<int> > dist(n, vector<int>(m, INF));
        queue<pair<int,int> > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int cur_i,cur_j;
        bool found = false;
        while (!q.empty()) {
            cur_i = q.front().first;
            cur_j = q.front().second;
            // check
            for (int step = 0; step < STEPS; ++step) {
                new_i = cur_i+dx[step];
                new_j = cur_j+dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 2) {
                    found = true;
                    break;
                }
            }
            if (found) {
                return dist[cur_i][cur_j];
            }
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                new_i = cur_i+dx[step];
                new_j = cur_j+dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 0 && dist[new_i][new_j] == INF) {
                    dist[new_i][new_j] = dist[cur_i][cur_j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
        return 0;
    }
};