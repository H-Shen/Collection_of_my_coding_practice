class Solution {
public:
    int rangeXorSum(vector<int>& pre, int l, int r) {
        if (l == 1) {
            return pre[r];
        }
        return pre[l-1]^pre[r];
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = (int)arr.size();
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1]^arr[i-1];
        }
        int q = (int)queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
            ans[i] = rangeXorSum(pre, queries[i][0]+1, queries[i][1]+1);
        }
        return ans;
    }
};