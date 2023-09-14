using ll = long long;

constexpr int STEPS = 4;
constexpr int MAXN = 305;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

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
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x,y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

bitset<MAXN> vis[MAXN];

void dfs(int i, int j, vector<vector<int>>& grid, int n) {
    vis[i][j] = true;
    int new_i,new_j;
    if (grid[i][j] != -1) {
        for (int step = 0; step < STEPS; ++step) {
            new_i = i + dx[step];
            new_j = j + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !vis[new_i][new_j] && grid[new_i][new_j] != -1) {
                DSU::merge(i*n+j,new_i*n+new_j);
                dfs(new_i,new_j,grid,n);
            }
        }
    }
}

class Solution {
public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        DSU::init(n*n);
        for (auto&i : vis) i.reset();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != -1 && !vis[i][j]) {
                    dfs(i,j,grid,n);
                }
            }
        }
        ll sum = 0;
        unordered_map<int,ll> group2sum;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != -1) {
                    group2sum[DSU::find(i*n+j)] += (ll)grid[i][j];
                    sum += (ll)grid[i][j];
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != -1) {
                    ans += sum - group2sum[DSU::find(i*n+j)];
                }
            }
        }
        return ans;
    }
};