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
        if (father[x] != x) father[x] = find(father[x]);
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
    int findCircleNum(vector<vector<int>>& M) {
        int n = (int)M.size();
        DSU::init(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M.at(i).at(j) == 1) {
                    DSU::merge(i, j);
                }
            }
        }
        constexpr int MAXN = 205;
        bitset<MAXN> groups;
        for (int i = 0; i < n; ++i) {
             groups[DSU::find(i)] = true;
        }
        return groups.count();
    }
};