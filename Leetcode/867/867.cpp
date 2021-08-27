class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix.front().size();
        vector<vector<int> > result(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result.at(j).at(i) = matrix.at(i).at(j);
            }
        }
        return result;
    }
};