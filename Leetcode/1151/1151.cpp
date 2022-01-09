class Solution {
public:
    int rangeSum(vector<int>&pre, int l, int r) {
        if (l == 0) return pre[r];
        return pre[r] - pre[l-1];
    }
    int minSwaps(vector<int>& data) {
        int counter = (int)count(data.begin(),data.end(),1);
        if (counter == 0) return 0;
        int n = (int)data.size();
        vector<int> pre(n);
        pre[0] = data[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + data[i];
        }
        int ans = numeric_limits<int>::max();
        for (int r = counter-1, l = 0; r < n; ++r, ++l) {
            ans = min(ans, counter - rangeSum(pre, l, r));
        }
        return ans;
    }
};