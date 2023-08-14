/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */

namespace DSU {
    vector<int> father, Size;
    int cc;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5, 1);
        cc = n;
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
        father[x] = y;
        --cc;
    }
}

class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        DSU::init(n);
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (categoryHandler->haveSameCategory(i,j)) {
                    DSU::merge(i,j);
                }
            }
        }
        return DSU::cc;
    }
};