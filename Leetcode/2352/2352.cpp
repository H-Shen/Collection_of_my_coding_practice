struct myHashFunc {
    size_t operator()(const vector<int> &A) const {
        size_t h = 0;
        for (const auto &i : A) {
            h ^= hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        unordered_map<vector<int>, int, myHashFunc> unmap;
        for (int i = 0; i < n; ++i) {
            ++unmap[grid[i]];
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> vec(n);
            for (int j = 0; j < n; ++j) {
                vec[j] = grid[j][i];
            }
            if (unmap.count(vec) > 0) {
                result += unmap[vec];
            }
        }
        return result;
    }
};