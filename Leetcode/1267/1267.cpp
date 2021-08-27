class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        constexpr int MAXN = 256;
        bitset<MAXN> vis[MAXN];
        int n = (int)grid.size();
        int m = (int)grid.front().size();
        for (int i = 0; i < n; ++i) {
            if (count(grid.at(i).begin(), grid.at(i).end(), 1) > 1) {
                for (int j = 0; j < m; ++j) {
                    if (grid.at(i).at(j) == 1) {
                        vis[i][j] = true;
                    }
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            int counter = 0;
            for (int i = 0; i < n; ++i) {
                if (grid.at(i).at(j) == 1) {
                    ++counter;
                }
            }
            if (counter > 1) {
                for (int i = 0; i < n; ++i) {
                    if (grid.at(i).at(j) == 1) {
                        vis[i][j] = true;
                    }
                }
            }
        }
        int result = 0;
        for (const auto &i : vis) {
            result += i.count();
        }
        return result;
    }
};