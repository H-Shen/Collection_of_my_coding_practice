class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {

        bool res = false;
        if (matrix.empty()) {
            return res;
        }

        vector<int> A(matrix.size());
        size_t len = 0;
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (matrix[i].size() > 0) {
                A[len++] = matrix[i].back();
            }
        }
        A.resize(len);

        if (A.empty() || target < matrix[0][0] || target > A.back()) {
            return res;
        }

        if (binary_search(A.begin(), A.end(), target)) {
            res = true;
            return res;
        }
        size_t pos = distance(A.begin(), upper_bound(A.begin(), A.end(), target));
        if (binary_search(matrix[pos].begin(), matrix[pos].end(), target)) {
            res = true;
        }

        return res;
    }
};