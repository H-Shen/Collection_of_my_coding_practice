bool check(const string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

struct VectorHashFunc {
    std::size_t operator()(const vector<pair<int,int> > &v) const {
        std::size_t h = v.size();
        for(const auto &i : v) {
            h ^= (hash<int>{}(i.first) ^ hash<int>{}(i.second))
            + 0x9e3779b9 
            + (h << 6) + (h >> 2);
        }
        return h;
    }
};

class Solution {
public:
    unordered_set<vector<pair<int,int> >, VectorHashFunc > vis;
    unordered_set<vector<pair<int,int> >, VectorHashFunc > unmap;
    void dfs(const string &s, vector<pair<int,int> > vec, int startIndex, int n) {
        if (startIndex >= n) {
            unmap.insert(vec);
            return;
        }
        if (vis.find(vec) != vis.end()) {
            return;
        }
        vis.insert(vec);
        for (int i = startIndex; i < n; ++i) {
            if (check(s, startIndex, i)) {
                auto vecCopy(vec);
                vecCopy.emplace_back(startIndex, i);
                dfs(s, vecCopy, i+1, n);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vis.clear();
        unmap.clear();
        vector<vector<string>> result;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (check(s, 0, i)) {
                dfs(s, vector<pair<int,int> >{{0,i}}, i+1, n);
            }
        }
        for (const auto &i : unmap) {
            vector<string> temp;
            for (const auto &[startIndex, endIndex] : i) {
                temp.emplace_back(s.substr(startIndex, endIndex - startIndex + 1));
            }
            result.emplace_back(temp);
        }
        return result;
    }
};