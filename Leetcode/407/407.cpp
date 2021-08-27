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
        if (x != father[x]) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            if (Size[x] > Size[y]) swap(x, y);
            Size[y] += Size[x];
            father[x] = y;
        }
    }
}

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        constexpr int STEPS = 4;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {1, -1, 0, 0};
        int n = (int)heightMap.size();
        int m = (int)heightMap.front().size();
        DSU::init(n * m);
        int maxHeight = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxHeight = max(maxHeight, heightMap[i][j]);
            }
        }
        vector<vector<int> > H(maxHeight + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                H[heightMap[i][j]].emplace_back(i*m+j);
            }
        }
        int total_water_added = 0;
        int water_added_at_current_level = 0;
        int new_i, new_j;
        for (int h = 0; h <= maxHeight; ++h) {
            for (const auto &pos : H[h]) {
                int i = pos / m;
                int j = pos % m;
                ++water_added_at_current_level;
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    DSU::merge(i*m+j, m*n);
                }
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && heightMap[new_i][new_j] <= heightMap[i][j]) {
                        DSU::merge(i*m+j, new_i*m+new_j);
                    }
                }
            }
            total_water_added += water_added_at_current_level - DSU::Size[DSU::find(m*n)] + 1;
        }
        return total_water_added;
    }
};