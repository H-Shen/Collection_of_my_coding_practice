namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        Size.resize(n+5,1);
        iota(father.begin(), father.end(), 0);
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
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}
constexpr int STEPS = 2;
const int dx[] = {0,1}; // right and down
const int dy[] = {1,0};
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = (int)grid1.size();
        int m = (int)grid1[0].size();
        DSU::init(n*m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] == 1) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid2[new_i][new_j] == 1) {
                            DSU::merge(i*m+j,new_i*m+new_j);
                        }
                    }
                }
            }
        }
        unordered_map<int,vector<int>> unmap;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] == 1) {
                    unmap[DSU::find(i*m+j)].emplace_back(i*m+j);
                }
            }
        }
        int ans = 0;
        bool flag;
        for (const auto &[k,v] : unmap) {
            flag = true;
            for (const auto &pos : v) {
                if (grid1[pos/m][pos%m] != 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) ++ans;
        }
        return ans;
    }
};