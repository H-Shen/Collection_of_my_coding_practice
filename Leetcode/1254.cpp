namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
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
        father[x] = y;
        Size[y] += Size[x];
    }
}

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        constexpr int STEPS = 4;
        constexpr int dx[] = {1, -1, 0, 0};
        constexpr int dy[] = {0, 0, -1, 1};
        int n = (int)grid.size();
        int m = (int)grid.front().size();
        DSU::init(n * m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid.at(i).at(j) == 0) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid.at(new_i).at(new_j) == 0) {
                            DSU::merge(i * m + j, new_i * m + new_j);
                        }
                    }
                }
            }
        }
        unordered_set<int> groups_touch_edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid.at(i).at(j) == 0) {
                    groups_touch_edges.insert(DSU::find(i * m + j));
                }
            }
        }
        unordered_set<int> result;
        int temp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid.at(i).at(j) == 0) {
                    temp = DSU::find(i * m + j);
                    if (groups_touch_edges.find(temp) == groups_touch_edges.end()) {
                        result.insert(temp);
                    }
                }
            }
        }
        return (int)result.size();
    }
};