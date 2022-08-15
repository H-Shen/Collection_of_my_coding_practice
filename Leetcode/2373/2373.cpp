constexpr int STEPS = 8;
const int dx[] = {-1,1,0,0,-1,1,-1,1};
const int dy[] = {0,0,-1,1,-1,1,1,-1};

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<int>> vec(n-2, vector<int>(n-2));
        int new_i, new_j;
        int pos = 0;
        int maxVal;
        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < n-1; ++j) {
                maxVal = grid[i][j];
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    maxVal = max(maxVal, grid[new_i][new_j]);
                }
                vec[pos / (n-2)][pos % (n-2)] = maxVal;
                ++pos;
            }
        }
        return vec;
    }
};