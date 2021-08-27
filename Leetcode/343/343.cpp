class Solution {
public:
    int integerBreak(int n) {
        vector<int> M(n + 1);
        M[2] = 1;
        for (int k = 3; k <= n; ++k) {
            for (int i = 1; i <= k - 1; ++i) {
                M[k] = max(M[k], max(i * (k - i), i *  M[k - i]));
            }
        }
        return M[n];
    }
};