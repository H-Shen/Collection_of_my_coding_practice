class Solution {
public:
    int maxScore(string s) {
        int n = (int)s.size();
        vector<int> zero(n + 1);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (s[i] == '0') {
                    zero[i] = 1;
                }
                continue;
            }
            if (s[i] == '0') {
                zero[i] = zero[i-1] + 1;
            } else {
                zero[i] = zero[i-1];
            }
        }
        vector<int> one(n + 1);
        for (int i = n-1; i >= 0; --i) {
            if (i == n - 1) {
                if (s[i] == '1') {
                    one[i] = 1;
                }
                continue;
            }
            if (s[i] == '1') {
                one[i] = one[i+1] + 1;
            } else {
                one[i] = one[i+1];
            }
        }
        int maxVal = -1;
        for (int i = 0; i < n - 1; ++i) {
            maxVal = max(maxVal, zero[i] + one[i+1]);
        }
        return maxVal;
    }
};