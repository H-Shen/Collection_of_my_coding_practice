class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        constexpr int MAXN = 205;
        bitset<MAXN> rowFlag, colFlag;
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    rowFlag[i] = true;
                    colFlag[j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (rowFlag[i]) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            if (colFlag[i]) {
                for (int j = 0; j < n; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};