constexpr int STEPS = 4;
const int dx[STEPS] = {0, 0, -1, 1};
const int dy[STEPS] = {-1, 1, 0, 0};

class Solution {
public:
    vector<vector<int> > dp;
    int n, m;
    int DP(int i, int j, const vector<vector<int> > &matrix) {
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        int new_i, new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = i + dx[step];
            new_j = j + dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && matrix[i][j] < matrix[new_i][new_j]) {
                dp[i][j] = max(dp[i][j], DP(new_i,new_j,matrix) + 1);
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = (int)matrix.size();
        m = (int)matrix.front().size();
        dp.resize(n, vector<int>(m, 0));
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                answer = max(answer, DP(i, j, matrix));
            }
        }
        return answer + 1;
    }
};