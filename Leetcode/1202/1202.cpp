namespace DSU {
    vector<int> Size,father;
    void init(int n) {
        vector<int>().swap(Size);
        vector<int>().swap(father);
        Size.resize(n+5,1);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
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
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = (int)s.size();
        DSU::init(n);
        for (const auto &i : pairs) {
            DSU::merge(i[0],i[1]);
        }
        unordered_map<int, deque<char> > unmap;
        for (int i = 0; i < n; ++i) {
            unmap[DSU::find(i)].emplace_back(s[i]);
        }
        for (auto &[k,v] : unmap) {
            sort(v.begin(), v.end());
        }
        for (int i = 0; i < n; ++i) {
            auto &dq = unmap[DSU::find(i)];
            s[i] = dq.front();
            dq.pop_front();
        }
        return s;
    }
};