namespace DSU {
    vector<int> Size, father;
    int cc;
    void init(int n) {
        vector<int>().swap(Size);
        vector<int>().swap(father);
        Size.resize(n+5,1);
        father.resize(n+5);
        iota(father.begin(), father.end(), 0);
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
        if (Size[x] > Size[y]) swap(x,y);
        Size[y] += Size[x];
        father[x] = y;
        --cc;
    }
}

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(), logs.end(), [](const auto &l, const auto &r){
            return l[0] < r[0];
        });
        DSU::init(N);
        for (const auto &i : logs) {
            DSU::merge(i[1], i[2]);
            if (DSU::cc == 1) {
                return i[0];
            }
        }
        return -1;
    }
};