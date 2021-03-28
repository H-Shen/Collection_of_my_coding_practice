class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        constexpr int MAXN = 105;
        bitset<MAXN> colMoreThanOneOne, rowMoreThanOneOne;
        int n = (int)mat.size();
        int m = (int)mat.front().size();
        int counter;
        for (int i = 0; i < n; ++i) {
            counter = 0;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    ++counter;
                    if (counter > 1) {
                        rowMoreThanOneOne[i] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            counter = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[j][i] == 1) {
                    ++counter;
                    if (counter > 1) {
                        colMoreThanOneOne[i] = true;
                    }
                }
            }
        }
        counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!colMoreThanOneOne[j] && !rowMoreThanOneOne[i] && mat[i][j] == 1) {
                    ++counter;
                }
            }
        }
        return counter;
    }
};