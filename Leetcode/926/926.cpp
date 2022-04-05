class Solution {
public:
    inline
    int rangeSum(vector<int>&pre, int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    int minFlipsMonoIncr(string s) {
        int n = (int)s.size();
        // 切分成左边k个0 右边n-k个1
        vector<int> pre(n);
        pre[0] = (s[0] == '1') ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + ((s[i] == '1') ? 1 : 0);
        }
        int minFlips = numeric_limits<int>::max();
        minFlips = min(minFlips, n - rangeSum(pre, 0, n-1));
        
        int leftFlips, rightFlips;
        for (int i = 0; i < n; ++i) {
            leftFlips = rangeSum(pre, 0, i);
            if (i < n-1) {
                rightFlips = n - (i+1) - rangeSum(pre, i+1, n-1);
            }
            else {
                rightFlips = 0;
            }
            minFlips = min(minFlips, leftFlips + rightFlips);
        }
        return minFlips;
    }
};