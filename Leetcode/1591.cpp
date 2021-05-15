constexpr int MAXN = 61;
constexpr int SIDES = 4;

class Solution {
public:
    vector<unordered_set<int> > overlapped;
    bool check(int index, vector<int> &vis) {
        if (vis[index]) {
            if (vis[index] == 1) {
                return true;
            }
            return false;
        }
        vis[index] = -1;
        for (const auto &i : overlapped[index]) {
            if (!check(i, vis)) {
                return false;
            }
        }
        vis[index] = 1;
        return true;
    }
    
    bool isPrintable(vector<vector<int>>& targetGrid) {
        decltype(overlapped)().swap(overlapped);
        overlapped.resize(MAXN);
        vector<vector<int> > v(MAXN, vector<int>(SIDES));
        for (auto &i : v) {
            i[0] = numeric_limits<int>::max();
            i[1] = numeric_limits<int>::max();
            i[2] = numeric_limits<int>::min();
            i[3] = numeric_limits<int>::min();
        }
        int n = (int)targetGrid.size();
        int m = (int)targetGrid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v[targetGrid[i][j]][0] = min(v[targetGrid[i][j]][0], i);
                v[targetGrid[i][j]][1] = min(v[targetGrid[i][j]][1], j);
                v[targetGrid[i][j]][2] = max(v[targetGrid[i][j]][2], i);
                v[targetGrid[i][j]][3] = max(v[targetGrid[i][j]][3], j);
            }
        }
        for (int idx = 0; idx < MAXN; ++idx) {
            for (int i = v[idx][0]; i <= v[idx][2]; ++i) {
                for (int j = v[idx][1]; j <= v[idx][3]; ++j) {
                    if (targetGrid[i][j] != idx) {
                        overlapped[idx].insert(targetGrid[i][j]);
                    }
                }
            }
        }
        for (int idx = 0; idx < MAXN; ++idx) {
            vector<int> vis(MAXN);
            if (!check(idx, vis)) {
                return false;
            }
        }
        return true;
    }
};