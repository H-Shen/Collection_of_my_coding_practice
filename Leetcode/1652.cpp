class Solution {
public:
    vector<int> pre;
    int rangeSum(int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n = (int)code.size();
        pre.resize(2*n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                pre[i] = code[i];
            } else {
                pre[i] = pre[i-1] + code[i];
            }
        }
        for (int i = n; i < 2*n; ++i) {
            pre[i] = pre[i-1] + code[i-n];
        }
        if (k == 0) {
            fill(code.begin(),code.end(),0);
        }
        else if (k > 0) {
            for (int i = 0; i < n; ++i) {
                code[i] = rangeSum(i+1,i+k);
            }
        }
        else {
            k = -k;
            for (int i = 0; i < n; ++i) {
                code[i] = rangeSum(i+n-k,i+n-1);
            }
        }
        return code;
    }
};