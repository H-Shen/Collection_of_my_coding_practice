using ll = long long;

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
        if (x != father[x]) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        father[x] = y;
        Size[y] += Size[x];
    }
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
}

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU::init(n);
        int u,v;
        for (auto&i : edges) {
            u = i[0];
            v = i[1];
            DSU::merge(u,v);
        }
        unordered_map<int,int> unmap;
        for (int i = 0; i < n; ++i) {
            ++unmap[DSU::find(i)];
        }
        vector<ll> vec;
        ll sum = 0;
        for (auto&[k,v] : unmap) {
            vec.emplace_back(v);
            sum += v;
        }
        ll cnt = 0;
        for (auto&i : vec) {
            cnt += (sum - i) * i;
        }
        return cnt >> 1;
    }
};