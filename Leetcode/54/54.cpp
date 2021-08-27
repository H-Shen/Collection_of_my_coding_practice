class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {

        vector<int> result;

        int m = static_cast<int>(matrix.size());
        if (m == 0)
            return result;

        int n = static_cast<int>(matrix[0].size());
        if (n == 0)
            return result;

        int leftCorneri = 0, leftCornerj = 0, rightCorneri = m - 1, rightCornerj = n - 1;
        int counter = 0;
        int i;
        int total = n * m;

        if (m == 1) {
            for (i = 0; i <= n - 1; i++) {
                result.push_back(matrix[0][i]);
            }
        }
        else if (n == 1) {
            for (i = 0; i <= m - 1; i++) {
                result.push_back(matrix[i][0]);
            }
        }
        else {
            while (1) {
                for (i = leftCorneri; i <= rightCornerj; i++) {
                    result.push_back(matrix[leftCorneri][i]);
                    counter++;
                }
                if (counter == total)
                    break;
                for (i = leftCornerj + 1; i <= rightCorneri; i++) {
                    result.push_back(matrix[i][rightCornerj]);
                    counter++;
                }
                if (counter == total)
                    break;
                for (i = rightCornerj - 1; i >= leftCornerj; i--) {
                    result.push_back(matrix[rightCorneri][i]);
                    counter++;
                }
                if (counter == total)
                    break;
                for (i = rightCorneri - 1; i >= leftCorneri + 1; i--) {
                    result.push_back(matrix[i][leftCornerj]);
                    counter++;
                }
                if (counter == total)
                    break;
                leftCorneri++; leftCornerj++; rightCorneri--; rightCornerj--;
            }
        }
        return result;
    }
};