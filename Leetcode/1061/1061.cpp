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
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        constexpr int MAXN = 26;
        DSU::init(MAXN);
        int u, v;
        for (size_t i = 0; i != A.size(); ++i) {
            u = A[i] - 'a';
            v = B[i] - 'a';
            DSU::merge(u, v);
        }
        unordered_map<char, set<char> > groups;
        for (int i = 0; i < MAXN; ++i) {
            groups[DSU::find(i) + 'a'].insert(i+'a');
        }
        for (auto &i : S) {
            i = *groups[DSU::find(i - 'a') + 'a'].begin();
        }
        return S;
    }
};