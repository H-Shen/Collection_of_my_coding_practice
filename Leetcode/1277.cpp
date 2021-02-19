namespace PrefixSum2D {
    vector<vector<int> > pre;
    int n, m;

    void init(const vector<vector<int> > &A) {

        if (A.empty() || A.front().empty()) return;
        n = (int) A.size();
        m = (int) A.front().size();
        decltype(pre)().swap(pre);
        pre.resize(n, vector<int>(m));

        pre[0][0] = A[0][0];
        for (int i = 1; i < m; ++i)
            pre[0][i] = pre[0][i - 1] + A[0][i];
        for (int i = 1; i < n; ++i)
            pre[i][0] = pre[i - 1][0] + A[i][0];
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + A[i][j];
    }

    int rangeSum(int r0, int c0, int r1, int c1) {
        if (r0 == 0 && c0 == 0) return pre[r1][c1];
        else if (r0 == 0 && c0 != 0) return pre[r1][c1] - pre[r1][c0 - 1];
        else if (r0 != 0 && c0 == 0) return pre[r1][c1] - pre[r0 - 1][c1];
        return pre[r1][c1] - pre[r0 - 1][c1] - pre[r1][c0 - 1] + pre[r0 - 1][c0 - 1];
    }
}

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        PrefixSum2D::init(matrix);        
        int maxSide = min(PrefixSum2D::n, PrefixSum2D::m);
        int counter = 0;
        for (int side = 1; side <= maxSide; ++side) {
            for (int i = 0; i < PrefixSum2D::n - side + 1; ++i) {
                for (int j = 0; j < PrefixSum2D::m - side + 1; ++j) {
                    if (PrefixSum2D::rangeSum(i, j, i + side - 1, j + side - 1) == side * side) {
                        ++counter;
                    }
                }
            }
        }
        return counter;
    }
};