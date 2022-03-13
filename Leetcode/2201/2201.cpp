constexpr int MAXN = 1005;

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
        father[x] = y;
        Size[y] += Size[x];
    }
}

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        DSU::init(n*n);
        int m = (int)artifacts.size();
        int r1, c1, r2, c2;
        for (int i = 0; i < m; ++i) {
            r1 = artifacts[i][0];
            c1 = artifacts[i][1];
            r2 = artifacts[i][2];
            c2 = artifacts[i][3];
            for (int r = r1; r <= r2; ++r) {
                for (int c = c1; c <= c2; ++c) {
                    DSU::merge(r1*n+c1, r*n+c);
                }
            }
        }
        unordered_set<int> vis;
        for (int i = 0; i < m; ++i) {
            vis.insert(DSU::find(artifacts[i][0]*n+artifacts[i][1]));
        }
        int counter = 0;
        unordered_map<int,int> unmap;
        int ancestor;
        for (auto& i : dig) {
            ancestor = DSU::find(i[0]*n+i[1]);
            if (vis.count(ancestor) > 0) {
                unmap[ancestor]++;
            }
        }
        for (auto&[k,v] : unmap) {
            if (DSU::Size[k]==v) ++counter;
        }
        return counter;
    }
};