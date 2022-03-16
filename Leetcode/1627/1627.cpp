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
    void merge(int x, int y) {
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
    // gcd(a,b) > th
    // n / (th+1) + n / (th+2) + n / (th+3) + ... + n / (th+n-th)
    // n (1/1+1/2+1/3+1/4+...+1/n)
    // 
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int m = (int)queries.size();
        vector<bool>ans(m);
        if (threshold == 0) {
            ans.flip();
            return ans;
        }
        DSU::init(n);
        for (int i = threshold+1; i <= n; ++i) {
            for (int j = 1; i*j <= n; ++j) {
                DSU::merge(i, i*j);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (DSU::find(queries[i][0]) == DSU::find(queries[i][1])) {
                ans[i] = true;
            }
        }
        return ans;
    }
};