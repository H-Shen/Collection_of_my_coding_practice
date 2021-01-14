namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        constexpr int STEPS = 4;
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        DSU::init(n * m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == grid[i][j]) {
                        DSU::merge(new_i * m + new_j, i * m + j);
                    }
                }
            }
        }
        int groupId = DSU::find(r0 * m + c0);
        vector<pair<int, int> > vec;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == grid[r0][c0] && DSU::find(i * m + j) == groupId) {
                    vec.emplace_back(i, j);
                }
            }
        }
        bool isAnswer;
        vector<pair<int, int> > ans;
        for (const auto &[i, j] : vec) {
            isAnswer = false;
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    if (grid[new_i][new_j] != grid[r0][c0]) {
                        isAnswer = true;
                        break;
                    }
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        isAnswer = true;
                        break;
                    }
                }
            }
            if (isAnswer) {
                ans.emplace_back(i, j);
            }
        }
        for (const auto &[i, j] : ans) {
            grid[i][j] = color;
        }
        return grid;
    }
};