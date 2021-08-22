constexpr int MAXN = 26;
constexpr int LENGTH = 505;

class Solution {
public:
    int pre[LENGTH][MAXN];
    int beautySum(string s) {
        memset(pre, 0, sizeof pre);
        int n = (int)s.size();
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                ++pre[i][s[j] - 'a'];
            }
        }
        int diff[MAXN];
        int maxFreq, minFreq;
        int sum = 0;
        for (int r = 1; r <= n; ++r) {
            for (int l = 1; l <= r; ++l) {
                for (int k = 0; k < MAXN; ++k) {
                    diff[k] = pre[r][k] - pre[l-1][k];
                }
                maxFreq = 0;
                for (int k = 0; k < MAXN; ++k) {
                    maxFreq = max(maxFreq, diff[k]);
                }
                if (maxFreq > 0) {
                    minFreq = LENGTH;
                    for (int k = 0; k < MAXN; ++k) {
                        if (diff[k] != 0) {
                            minFreq = min(minFreq, diff[k]);
                        }
                    }
                    sum += maxFreq - minFreq;
                }
            }
        }
        return sum;
    }
};