namespace DSU {
    vector<int> Size, father;
    void init(int n) {
        vector<int>().swap(Size);
        vector<int>().swap(father);
        Size.resize(n + 5, 1);
        father.resize(n + 5, 0);
        iota(father.begin(), father.end(), 0);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        constexpr int STEPS = 4;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        DSU::init(n * m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1) {
                            DSU::merge(new_i * m + new_j, i * m + j);
                        }
                    }
                }
            }
        }
        unordered_map<int, int> groups;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++groups[DSU::find(i * m + j)];
                }
            }
        }
        int maxValue = 0;
        for (const auto &[k, v] : groups) {
            maxValue = max(maxValue, v);
        }
        return maxValue;
    }
};