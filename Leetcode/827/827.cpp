namespace DSU {
    vector<int> Size, father;
    void init(int n) {
        vector<int>().swap(Size);
        vector<int>().swap(father);
        Size.resize(n+5,1);
        father.resize(n+5,1);
        iota(father.begin(),father.end(),0);
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
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        DSU::init(n*n);
        int new_i,new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i+dx[step];
                        new_j = j+dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1) {
                            DSU::merge(i*n+j,new_i*n+new_j);
                        }
                    }
                }
            }
        }
        int maxSize = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    maxSize = max(maxSize, DSU::Size[DSU::find(i*n+j)]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> groupsAround;
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i+dx[step];
                        new_j = j+dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1) {
                            groupsAround.insert(DSU::find(new_i*n+new_j));
                        }
                    } 
                    int temp = 1;   // add self
                    for (const auto &k : groupsAround) {
                        temp += DSU::Size[DSU::find(k)];
                    }
                    maxSize = max(maxSize, temp);
                }
            }
        }
        return maxSize;
    }
};