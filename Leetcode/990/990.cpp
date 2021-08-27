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
    bool equationsPossible(vector<string>& equations) {
        constexpr int MAXN = 26;
        DSU::init(MAXN);
        int u, v;
        vector<pair<int, int> > inequalityRestrictions;
        for (const auto &i : equations) {
            u = i.at(0) - 'a';
            v = i.at(3) - 'a';
            if (i.at(1) == '=') {
                DSU::merge(u, v);
            } else {
                inequalityRestrictions.emplace_back(u, v);
            }
        }
        for (const auto &[i, j] : inequalityRestrictions) {
            if (DSU::is_same_group(i, j)) {
                return false;
            }
        }
        return true;
    }
};