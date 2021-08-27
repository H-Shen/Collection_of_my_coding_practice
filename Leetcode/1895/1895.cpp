class Solution {
public:
    vector<vector<int> > row_presum;
    vector<vector<int> > col_presum;
    int row_rangesum(int row, int i, int j) {
        if (i == 0) {
            return row_presum[row][j];
        }
        return row_presum[row][j] - row_presum[row][i-1];
    }
    int col_rangesum(int col, int i, int j) {
        if (i == 0) {
            return col_presum[col][j];
        }
        return col_presum[col][j] - col_presum[col][i-1];
    }
    bool check(const vector<vector<int>>& grid, int i, int j, int Size) {
        int ans;
        // row check
        int rowSum = -1;
        for (int new_i = i; new_i < i + Size; ++new_i) {
            int sum = row_rangesum(new_i, j, j + Size - 1);
            if (rowSum == -1) {
                rowSum = sum;
            }
            else if (rowSum != sum) {
                return false;
            }
        }
        ans = rowSum;
        // col check
        int colSum = -1;
        for (int new_j = j; new_j < j + Size; ++new_j) {
            int sum = col_rangesum(new_j, i, i + Size - 1);
            if (colSum == -1) {
                colSum = sum;
            }
            else if (colSum != sum) {
                return false;
            }
        }
        // left diagon check
        int lsum = 0;
        for (int new_i = i, new_j = j; new_i < i + Size; ++new_i, ++new_j) {
            lsum += grid[new_i][new_j];
        }
        if (lsum != ans) {
            return false;
        }
        // right diagon check
        int rsum = 0;
        for (int new_i = i + Size - 1, new_j = j; new_i >= i; --new_i, ++new_j) {
            rsum += grid[new_i][new_j];
        }
        if (rsum != ans) {
            return false;
        }
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        decltype(row_presum)().swap(row_presum);
        decltype(col_presum)().swap(col_presum);
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        row_presum.resize(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    row_presum[i][j] = grid[i][j];
                }
                else {
                    row_presum[i][j] = row_presum[i][j-1] + grid[i][j];
                }
            }
        }
        col_presum.resize(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    col_presum[i][j] = grid[j][i];
                }
                else {
                    col_presum[i][j] = col_presum[i][j-1] + grid[j][i];
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int k = min(n-i,m-j);
                if (k <= ans) {
                    continue;
                }
                for (; k >= ans; --k) {
                    if (check(grid, i, j, k)) {
                        ans = k;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};