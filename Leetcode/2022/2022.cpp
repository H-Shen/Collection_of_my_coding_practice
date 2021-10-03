class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int length = (int)original.size();
        if (length != m*n) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ans(m, vector<int>(n));
        int index = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = original[index];
                ++index;
            }
        }
        return ans;
    }
};