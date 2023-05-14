namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (x != father[x]) {
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
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU::init(n);
        unordered_map<int,int> root2edges;
        int u,v;
        for (auto&i : edges) {
            u = i[0];
            v = i[1];
            DSU::merge(u,v);
        }
        for (auto&i : edges) {
            u = i[0];
            ++root2edges[DSU::find(u)];
        }
        for (int i = 0; i < n; ++i) {
            if (i == DSU::find(i) && root2edges.count(i) == 0) {
                root2edges[i] = 0;
            }
        }
        int cnt = 0;
        for (auto&[k,v] : root2edges) {
            if ( ((DSU::Size[k]*(DSU::Size[k]-1))>>1) == v) {
                ++cnt;
            }
        }
        return cnt;
    }
};