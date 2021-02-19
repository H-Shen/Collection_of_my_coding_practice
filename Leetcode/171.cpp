class Solution {
public:
    int titleToNumber(string s) {
        int n = (int)s.size();
        vector<int> pre(n);
        pre[0] = 1;
        for (int i = 1; i < n; ++i) pre[i] = pre[i-1]*26;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (s[i] - 'A' + 1) * pre[n - 1 - i];
        }
        return sum;
    }
};