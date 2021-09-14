constexpr int MAXN = 505;
bitset<MAXN> bs[MAXN];

class Solution {
public:
    void solveFromLeft(int row, int n, vector<int>& dp) {
        for (int i = 0; i < n; ++i) {
            if (bs[row][i]) {
                if (i == 0) {
                    dp[i] = 1;
                }
                else {
                    dp[i] = dp[i-1]+1;
                }
            }
            else {
                dp[i] = 0;
            }
        }
    }
    void solveFromRight(int row, int n, vector<int>& dp) {
        for (int i = n-1; i >= 0; --i) {
            if (bs[row][i]) {
                if (i == n-1) {
                    dp[i] = 1;
                }
                else {
                    dp[i] = dp[i+1]+1;
                }
            }
            else {
                dp[i] = 0;
            }
        }
    }
    void solveFromUp(int col, int n, vector<int>& dp) {
        for (int i = 0; i < n; ++i) {
            if (bs[i][col]) {
                if (i == 0) {
                    dp[i] = 1;
                }
                else {
                    dp[i] = dp[i-1]+1;
                }
            }
            else {
                dp[i] = 0;
            }
        }
    }
    void solveFromDown(int col, int n, vector<int>& dp) {
        for (int i = n-1; i >= 0; --i) {
            if (bs[i][col]) {
                if (i == n-1) {
                    dp[i] = 1;
                }
                else {
                    dp[i] = dp[i+1]+1;
                }
            }
            else {
                dp[i] = 0;
            }
        }
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // reset
        for (int i = 0; i < MAXN; ++i) {
            bs[i].reset();
            bs[i].flip();
        }
        for (const auto &i : mines) {
            bs[i[0]][i[1]] = false;
        }
        // dp from 4 directions
        // left
        vector<vector<int>> dpFromLeft(n, vector<int>(n));
        for (int row = 0; row < n; ++row) {
            solveFromLeft(row, n, dpFromLeft[row]);
        }
        // right
        vector<vector<int>> dpFromRight(n, vector<int>(n));
        for (int row = 0; row < n; ++row) {
            solveFromRight(row, n, dpFromRight[row]);
        }
        // up
        vector<vector<int>> dpFromUp(n, vector<int>(n));
        for (int col = 0; col < n; ++col) {
            solveFromUp(col, n, dpFromUp[col]);
        }
        // down
        vector<vector<int>> dpFromDown(n, vector<int>(n));
        for (int col = 0; col < n; ++col) {
            solveFromDown(col, n, dpFromDown[col]);
        }
        int maxK = 0;
        int temp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (bs[i][j]) {
                    temp = numeric_limits<int>::max();
                    temp = min(temp, dpFromLeft[i][j]);
                    temp = min(temp, dpFromRight[i][j]);
                    temp = min(temp, dpFromUp[j][i]);
                    temp = min(temp, dpFromDown[j][i]);
                    maxK = max(maxK, temp);
                }
            }
        }
        return maxK;
    }
};