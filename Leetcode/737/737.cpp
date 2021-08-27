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
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        int id = 0;
        unordered_map<string, int> unmap;
        for (const auto &i : words1) {
            if (unmap.find(i) == unmap.end()) {
                unmap[i] = id;
                ++id;
            }
        }
        for (const auto &i : words2) {
            if (unmap.find(i) == unmap.end()) {
                unmap[i] = id;
                ++id;
            }
        }
        for (const auto &i : pairs) {
            for (const auto &j : i) {
                if (unmap.find(j) == unmap.end()) {
                    unmap[j] = id;
                    ++id;
                }
            }
        }
        DSU::init(id);
        for (const auto &i : pairs) {
            DSU::merge(unmap[i[0]], unmap[i[1]]);
        }
        for (size_t i = 0; i != words1.size(); ++i) {
            if (DSU::find(unmap[words1[i]]) != DSU::find(unmap[words2[i]])) {
                return false;
            }
        }
        return true;
    }
};