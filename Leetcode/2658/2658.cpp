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
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

constexpr int STEPS = 4;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

class Solution {
public:
    int n, m;
    int findMaxFish(vector<vector<int>>& grid) {
        n = (int)grid.size();
        m = (int)grid[0].size();
        DSU::init(n*m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != 0) {
                            DSU::merge(new_i*m+new_j,i*m+j);
                        }
                    }
                }
            }
        }
        unordered_map<int,int> unmap;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    unmap[DSU::find(i*m+j)] += grid[i][j];
                }
            }
        }
        int maxVal = 0;
        for (const auto &[k,v] : unmap) {
            maxVal = max(maxVal, v);
        }
        return maxVal;
    }
};
