class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {

        auto judge = [](const vector<vector<int> > &A, int i, int j) {
            int lastVal = -1;
            while (true) {
                try {
                    if (lastVal == -1) {
                        lastVal = A.at(static_cast<unsigned long>(i++)).at(static_cast<unsigned long>(j++));
                    } else if (lastVal != A.at(static_cast<unsigned long>(i)).at(static_cast<unsigned long>(j))) {
                        return false;
                    } else {
                        ++i;
                        ++j;
                    }
                } catch (...) {
                    break;
                }
            }
            return true;
        };

        size_t i = 0, j = 0;
        for (i = 0; i < matrix.size(); ++i) {
            if (!judge(matrix, i, 0)) {
                return false;
            }
        }
        for (i = 1; i < matrix[0].size(); ++i) {
            if (!judge(matrix, 0, i)) {
                return false;
            }
        }
        return true;
    }
};