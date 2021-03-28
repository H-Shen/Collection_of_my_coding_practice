namespace PrefixSum2D {
    vector<vector<int> > pre;
    int n, m;

    void init(const vector<vector<char> > &A) {

        if (A.empty() || A.front().empty()) return;
        n = (int) A.size();
        m = (int) A.front().size();
        decltype(pre)().swap(pre);
        pre.resize(n, vector<int>(m));

        pre[0][0] = A[0][0] - '0';
        for (int i = 1; i < m; ++i)
            pre[0][i] = pre[0][i - 1] + (A[0][i] - '0');
        for (int i = 1; i < n; ++i)
            pre[i][0] = pre[i - 1][0] + (A[i][0] - '0');
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (A[i][j] - '0');
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
    int maximalSquare(vector<vector<char>>& matrix) {
        PrefixSum2D::init(matrix);
        int area = 0;
        int maxSize = max(PrefixSum2D::m, PrefixSum2D::n);
        for (int side = maxSize; side >= 1; --side) {
            for (int i = 0; i + side - 1 < PrefixSum2D::n; ++i) {
                for (int j = 0; j + side - 1 < PrefixSum2D::m; ++j) {
                    if (PrefixSum2D::rangeSum(i, j, i + side - 1, j + side - 1) == side * side) {
                        area = side * side;
                        return area;
                    }
                }
            }
        }
        return area;
    }
};