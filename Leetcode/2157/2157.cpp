constexpr int MAXN = 26;

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
    // O(26*26*n)
    vector<int> groupStrings(vector<string>& words) {
        int n = (int)words.size();
        int val, temp, temp2;
        unordered_map<int,int> val2id;
        unordered_map<int,int>::iterator iter;
        int id = 0;
        for (int i = 0; i < n; ++i) {
            val = 0;
            for (const auto&ch : words[i]) {
                // x |= (1<<(k-1)) 把右边第k位变成1
                val |= (1<<((ch-'a'+1)-1));
            }
            if (val2id.count(val) == 0) {
                val2id[val] = id;
                ++id;
            }
        }
        DSU::init(id);
        int u;
        for (int i = 0; i < n; ++i) {
            val = 0;
            for (const auto&ch : words[i]) {
                // x |= (1<<(k-1)) 把右边第k位变成1
                val |= (1<<((ch-'a'+1)-1));
            }
            u = val2id[val];
            // add
            for (int i = 1; i <= MAXN; ++i) {
                // 判断这一位上是不是0
                if (!((val >> (i-1)) & 1)) {
                    temp = val;
                    // 将这一位取反
                    temp ^= (1<<(i-1));
                    iter = val2id.find(temp);
                    if (iter != val2id.end()) {
                        DSU::merge(u, iter->second);
                    }
                }
            }
            // delete
            for (int i = 1; i <= MAXN; ++i) {
                // 判断这一位上是不是1
                if ((val >> (i-1)) & 1) {
                    temp = val;
                    // 将这一位取反
                    temp ^= (1<<(i-1));
                    iter = val2id.find(temp);
                    if (iter != val2id.end()) {
                        DSU::merge(u, iter->second);
                    }
                }
            }
            // remove and place on another '0'
            for (int i = 1; i <= MAXN; ++i) {
                if ((val >> (i-1)) & 1) {
                    temp = val;
                    temp ^= (1<<(i-1));
                    for (int j = 1; j <= MAXN; ++j) {
                        if (!((temp >> (j-1)) & 1)) {
                            temp2 = temp;
                            temp2 ^= (1<<(j-1));
                            iter = val2id.find(temp2);
                            if (iter != val2id.end()) {
                                DSU::merge(u, iter->second);
                            }
                        }
                    }
                }
            }
        }
        vector<int> group2number(id);
        for (int i = 0; i < n; ++i) {
            val = 0;
            for (const auto&ch : words[i]) {
                // x |= (1<<(k-1)) 把右边第k位变成1
                val |= (1<<((ch-'a'+1)-1));
            }
            ++group2number[DSU::find(val2id[val])];
        }
        int counter = 0;
        int maxSize = 0;
        for (int i = 0; i < id; ++i) {
            if (group2number[i] > 0) {
                ++counter;
                maxSize = max(maxSize, group2number[i]);
            }
        }
        return vector<int>{counter,maxSize};
    }
};