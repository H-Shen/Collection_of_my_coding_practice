namespace DSU {
    vector<int> father, Size;
    int cc;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
        cc = n;
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
        --cc;
        if (Size[x] < Size[y]) {
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}
class Solution {
public:
    bool solve(string&a, string&b) {
        int counter = 0;
        vector<int> v;
        for (size_t i = 0; i != a.size(); ++i) {
            if (a[i] != b[i]) {
                ++counter;
                if (counter > 2) return false;
                v.emplace_back(i);
            }
        }
        if (counter == 0) return true;
        if (counter == 2 && a[v[0]] == b[v[1]] && a[v[1]] == b[v[0]]) return true;
        return false;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = (int)strs.size();
        DSU::init(n);
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (solve(strs[i],strs[j])) DSU::merge(i,j);
            }
        }
        return DSU::cc;
    }
};