// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e

class Solution {
public:
    bool Find(int target, vector <vector<int>> matrix) {

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