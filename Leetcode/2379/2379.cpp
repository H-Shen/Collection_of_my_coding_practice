class Solution {
public:
    inline
    int rangeSum(vector<int>&pre, int l, int r) const {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    int minimumRecolors(string blocks, int k) {
        int n = (int)blocks.size();
        vector<int> pre(n);
        pre[0] = (blocks[0] == 'W') ? 0 : 1;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + ((blocks[i] == 'W') ? 0 : 1);
        }
        int ans = numeric_limits<int>::max();
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = min(ans, k - rangeSum(pre, i, i+k-1));
        } 
        return ans;
    }
};