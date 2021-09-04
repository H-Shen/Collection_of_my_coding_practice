constexpr int STEPS = 2;
const int dx[] = {0,1};
const int dy[] = {1,0};

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
        if (Size[x] >
            Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = (int)land.size();
        int m = (int)land[0].size();
        DSU::init(n*m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (land[i][j] == 1) {
                    int new_i,new_j;
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i+dx[step];
                        new_j = j+dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && land[new_i][new_j] == 1) {
                            DSU::merge(new_i*m+new_j,i*m+j);
                        }
                    }
                }
            }
        }
        unordered_map<int,vector<pair<int,int>>> unmap;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (land[i][j] == 1) {
                    unmap[DSU::find(i*m+j)].emplace_back(i,j);
                }
            }
        }
        vector<vector<int>> ans;
        for (auto &[k,v] : unmap) {
            auto iter = minmax_element(v.begin(),v.end());
            ans.emplace_back(vector<int>{iter.first->first,iter.first->second,iter.second->first,iter.second->second});
        }
        return ans;
    }
};