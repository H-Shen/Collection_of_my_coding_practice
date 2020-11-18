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
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU::init((int)edges.size());
        int result_u = -1, result_v = -1;
        int u, v;
        for (const auto &i : edges) {
            u = i.front();
            v = i.back();
            if (DSU::is_same_group(u, v)) {
                result_u = u;
                result_v = v;
            } else {
                DSU::merge(u, v);
            }
        }
        return {result_u, result_v};
    }
};