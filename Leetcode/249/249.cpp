constexpr int MAXN = 26;

vector<int> getHashVec(const string &s) {
    vector<int> ans;
    int n = (int)s.size();
    ans.emplace_back(n);
    int diff;
    for (int i = 1; i < n; ++i) {
        diff = s[i]-s[i-1];
        if (diff < 0) diff += MAXN;
        ans.emplace_back(diff);
    }
    return ans;
}

struct myHashFunc {
    size_t operator() (const vector<int> &A) const {
        size_t h = 0;
        for (const auto &i : A) {
            h ^= hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }  
};

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<vector<int>, vector<string>, myHashFunc > unmap;
        for (const auto &i : strings) {
            unmap[getHashVec(i)].emplace_back(i);
        }
        vector<vector<string> > vec(unmap.size());
        auto iter = vec.begin();
        for (const auto &[k,v] : unmap) {
            *iter = v;
            ++iter;
        }
        return vec;
    }
};