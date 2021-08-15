class Solution {
public:
    int g(int n) {
        return n^(n>>1);
    }
    vector<int> grayCode(int n) {
        int length = 1<<n;
        vector<int> ans(length);
        for (int i = 0; i < length; ++i) {
            ans[i] = g(i);
        }
        return ans;
    }
};