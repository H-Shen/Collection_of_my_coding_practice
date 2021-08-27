void f(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (target == mat) return true;
        for (int i = 0; i < 3; ++i) {
            f(mat);
            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};