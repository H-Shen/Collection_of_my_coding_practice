// https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a

class Solution {
public:
    vector<int> printMatrix(vector <vector<int>> mat) {

        vector<int> result;
        int n = mat.size();
        if (n == 0)
            return result;

        int m = mat[0].size();
        if (m == 0)
            return result;

        int leftCorneri = 0, leftCornerj = 0, rightCorneri = n - 1, rightCornerj = m - 1;
        int counter = 0;
        int i;
        int total = n * m;

        if (n == 1) {
            for (i = 0; i <= m - 1; i++) {
                result.push_back(mat[0][i]);
            }
        } else if (m == 1) {
            for (i = 0; i <= n - 1; i++) {
                result.push_back(mat[i][0]);
            }
        } else {
            while (1) {
                for (i = leftCorneri; i <= rightCornerj; i++) {
                    result.push_back(mat[leftCorneri][i]);
                    counter++;
                }
                if (counter == total)
                    break;
                for (i = leftCornerj + 1; i <= rightCorneri; i++) {
                    result.push_back(mat[i][rightCornerj]);
                    counter++;
                }
                if (counter == total)
                    break;
                for (i = rightCornerj - 1; i >= leftCornerj; i--) {
                    result.push_back(mat[rightCorneri][i]);
                    counter++;
                }
                if (counter == total)
                    break;
                for (i = rightCorneri - 1; i >= leftCorneri + 1; i--) {
                    result.push_back(mat[i][leftCornerj]);
                    counter++;
                }
                if (counter == total)
                    break;
                leftCorneri++;
                leftCornerj++;
                rightCorneri--;
                rightCornerj--;
            }
        }
        return result;
    }
};