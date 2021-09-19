// prefix 2d sum
vector<vector<int>> pre;

void init(vector<vector<int>>& A) {
    int n = (int)A.size();
    int m = (int)A[0].size();
    decltype(pre)().swap(pre);
    pre.resize(n, vector<int>(m));
    pre[0][0] = A[0][0];
    for (int i = 1; i < m; ++i) {
        pre[0][i] = pre[0][i-1] + A[0][i];
    }
    for (int i = 1; i < n; ++i) {
        pre[i][0] = pre[i-1][0] + A[i][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + A[i][j];
        }
    }
}

int s(int i0, int j0, int i1, int j1) {
    if (i0 == 0 && j0 == 0) {
        return pre[i1][j1];
    }
    else if (i0 == 0 && j0 != 0) {
        return pre[i1][j1] - pre[i1][j0-1];
    }
    else if (i0 != 0 && j0 == 0) {
        return pre[i1][j1] - pre[i0-1][j1];
    }
    return pre[i1][j1] - pre[i1][j0-1] - pre[i0-1][j1] + pre[i0-1][j0-1];
}

bool check(int length, int n, int m, int threshold) {
    for (int i = 0; i + length <= n; ++i) {
        for (int j = 0; j + length <= m; ++j) {
            if (s(i, j, i+length-1, j+length-1) <= threshold) {
                return true;
            }
        }
    }
    return false;
}

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        init(mat);
        int ans = numeric_limits<int>::min();
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        int l = 1;
        int r = min(n, m);
        int mid;
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check(mid, n, m, threshold)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans == numeric_limits<int>::min() ? 0 : ans;
    }
};