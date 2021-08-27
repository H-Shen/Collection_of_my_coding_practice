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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU::init(n);
        int redundant = 0;
        int u, v;
        for (const auto &e : connections) {
            u = e.at(0);
            v = e.at(1);
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
            } else {
                ++redundant;
            }
        }
        unordered_set<int> cc;
        for (int i = 0; i < n; ++i) {
            cc.insert(DSU::find(i));
        }
        int cc_counter = (int)cc.size();
        if (cc_counter > redundant + 1) {
            return -1;
        }
        return cc_counter - 1;
    }
};