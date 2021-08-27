class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix.at(0).empty()) {
            return false;
        }

        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix.at(0).size());

        int current_i = 0;
        int current_j = n - 1;
        bool haveAns = false;
        while (current_i < m && current_j >= 0) {
            if (target < matrix.at(current_i).at(current_j)) {
                --current_j;
            } else if (target > matrix.at(current_i).at(current_j)) {
                ++current_i;
            } else {
                haveAns = true;
                break;
            }
        }
        return haveAns;
    }
};