class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix.front().size();
        vector<int> rowMin(n);
        vector<int> colMax(m);
        for (int i = 0; i < n; ++i) {
            rowMin[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }
        for (int i = 0; i < m; ++i) {
            int maxVal = -1;
            for (int j = 0; j < n; ++j) {
                maxVal = max(maxVal, matrix[j][i]);
            }
            colMax[i] = maxVal;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == colMax[j] && matrix[i][j] == rowMin[i]) {
                    result.emplace_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};