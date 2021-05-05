class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int> > A(m, vector<int>(n));
        for (const auto &u : indices) {
            int i = u[0];
            int j = u[1];
            for (auto &k : A[i]) {
                ++k;
            }
            for (int k = 0; k < m; ++k) {
                ++A[k][j];
            }
        }
        int counter = 0;
        for (const auto &i : A) {
            for (const auto &j : i) {
                if (j % 2 != 0) {
                    ++counter;
                }
            }
        }
        return counter;
    }
};