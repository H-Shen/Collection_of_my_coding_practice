class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto&i : grid) {
            sort(i.begin(),i.end());
        }
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int maxVal = 0;
            for (int j = 0; j < n; ++j) {
                maxVal = max(maxVal, grid[j][i]);
            }
            ans += maxVal;
        }
        return ans;
    }
};