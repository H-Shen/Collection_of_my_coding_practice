namespace DSU {
    vector<int> Size, father;
    void init(int n) {
        vector<int>().swap(Size);
        vector<int>().swap(father);
        Size.resize(n+5,1);
        father.resize(n+5);
        iota(father.begin(), father.end(), 0);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU::init(n);
        for (const auto &i : edges) {
            DSU::merge(i[0], i[1]);
        }
        unordered_set<int> unset;
        for (int i = 0; i < n; ++i) {
            unset.insert(DSU::find(i));
        }
        return (int)unset.size();
    }
};