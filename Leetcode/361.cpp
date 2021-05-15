class Solution {
public:
    vector<int> solve(const vector<char> &v) {
        int length = (int)v.size();
        vector<int> result(length, -1);
        for (int i = 0; i < length; ++i) {
            if (v[i] == 'W') {
                result[i] = 0;
            }
        }
        int startIndex = -1;
        int endIndex = -1;
        vector<pair<int,int> > temp;
        for (int i = 0; i < length; ++i) {
            if (result[i] == 0) {
                if (endIndex != -1) {
                    temp.emplace_back(startIndex, endIndex);
                    startIndex = -1;
                    endIndex = -1;
                }
            }
            else {
                if (endIndex == -1) {
                    startIndex = i;
                    endIndex = i;
                } else {
                    ++endIndex;
                }
            }
        }
        if (endIndex != -1) {
            temp.emplace_back(startIndex, endIndex);
        }
        for (const auto &[i,j] : temp) {
            int counter = 0;
            for (int idx = i; idx <= j; ++idx) {
                if (v[idx] == 'E') {
                    ++counter;
                }
            }
            for (int idx = i; idx <= j; ++idx) {
                result[idx] = counter;
            }
        }
        return result;
    }
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        vector<vector<int> > dpRow(n);
        for (int i = 0; i < n; ++i) {
            dpRow[i] = solve(grid[i]);
        }
        vector<vector<int> > dpCol(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            vector<char> temp(n);
            for (int j = 0; j < n; ++j) {
                temp[j] = grid[j][i];
            }
            auto p = solve(temp);
            for (int j = 0; j < n; ++j) {
                dpCol[j][i] = p[j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') {
                    ans = max(ans, dpRow[i][j]+dpCol[i][j]);
                }
            }
        }
        return ans;
    }
};