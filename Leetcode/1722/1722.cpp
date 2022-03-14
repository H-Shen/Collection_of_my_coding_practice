constexpr int MAXN = 1e5+5;

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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = (int)source.size();
        DSU::init(n);
        for (auto&i : allowedSwaps) {
            DSU::merge(i[0],i[1]);
        }
        unordered_map<int, unordered_map<int,int>> id2freq;
        for (int i = 0; i < n; ++i) {
            ++id2freq[DSU::find(i)][source[i]];
        }
        int counter = 0;
        int groupId;
        for (int i = 0; i < n; ++i) {
            groupId = DSU::find(i);
            auto it = id2freq.find(groupId);
            auto iter = it->second.find(target[i]);
            if (iter != it->second.end()) {
                --iter->second;
                if (iter->second == 0) {
                    it->second.erase(iter);
                }
            } else {
                ++counter;
            }
        }
        return counter;
    }
};