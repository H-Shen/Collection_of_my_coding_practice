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
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
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
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = (int)edges.size();
        if (m != n - 1) return false;
        DSU::init(n);
        for (const auto &i : edges) {
            DSU::merge(i[0], i[1]);
        }
        unordered_set<int> unset;
        for (int i = 0; i < n; ++i) {
            unset.insert(DSU::find(i));
            if (unset.size() > 1) {
                return false;
            }
        }
        return true;
    }
};