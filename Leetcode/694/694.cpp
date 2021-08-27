namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x); y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        constexpr int STEPS = 4;
        const int dx[] = {0,0,-1,1};
        const int dy[] = {-1,1,0,0};
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        DSU::init(n*m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1) {
                            DSU::merge(i*m+j, new_i*m+new_j);
                        }
                    }
                }
            }
        }
        unordered_map<int, vector<pair<int,int> > > groups;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    groups[DSU::find(i*m+j)].emplace_back(i,j);
                }
            }
        }
        for (auto &[k,v] : groups) {
            sort(v.begin(), v.end());
            int diff_i = v.front().first;
            int diff_j = v.front().second;
            for (auto &[i,j] : v) {
                i -= diff_i;
                j -= diff_j;
            }
        }
        struct VectorHashFunc {
            std::size_t operator()(const vector<pair<int,int> > &v) const {
                std::size_t h = v.size();
                for(const auto &i : v) {
                    h ^= (hash<int>{}(i.first) ^ hash<int>{}(i.second))
                    + 0x9e3779b9 
                    + (h << 6) + (h >> 2);
                }
                return h;
            }
        };
        unordered_set<vector<pair<int,int> >, VectorHashFunc> unset;
        for (const auto &[k,v] : groups) {
            unset.insert(v);
        }
        return unset.size();
    }
};