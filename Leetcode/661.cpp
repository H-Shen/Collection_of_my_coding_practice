class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        constexpr int STEPS = 8;
        const int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
        const int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
        
        int n = (int)M.size();
        int m = (int)M.front().size();
        vector<vector<int> > result(n, vector<int>(m, 0));
        
        int new_i, new_j, counter, sum;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                counter = 1;
                sum = M[i][j];
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                        ++counter;
                        sum += M[new_i][new_j];
                    }
                }
                result[i][j] = sum / counter;
            }
        }
        return result;
    }
};