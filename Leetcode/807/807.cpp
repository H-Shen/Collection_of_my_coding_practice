class Solution {
public:
    // greedy
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<int> colMax(n);
        int maxVal;
        for (int i = 0; i < n; ++i) {
            maxVal = numeric_limits<int>::min();
            for (int j = 0; j < n; ++j) {
                maxVal = max(maxVal, grid[j][i]);
            }
            colMax[i] = maxVal;
        }
        vector<int> rowMax(n);
        for (int i = 0; i < n; ++i) {
            rowMax[i] = *max_element(grid[i].begin(),grid[i].end());
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};