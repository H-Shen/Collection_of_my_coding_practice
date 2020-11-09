class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, i = 0, j = 0;
        try {
            while (true) {
                sum += mat.at(i).at(j);
                ++i;
                ++j;
            }
        } catch (...) {}
        i = 0;
        j = (int)mat.size() - 1;
        try {
            while (true) {
                sum += mat.at(i).at(j);
                ++i;
                --j;
            }
        } catch (...) {}
        if (mat.size() % 2 != 0) {
            sum -= mat.at(mat.size() / 2).at(mat.size() / 2);
        }
        return sum;
    }
};