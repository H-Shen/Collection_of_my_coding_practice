class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = (int)s.size();
        vector<int> pre(n+1);
        vector<int> posOfCandles;
        // '*': 1, '|': 0
        for (int i = 1; i <= n; ++i) {
            if (s[i-1] == '*') {
                pre[i] = pre[i-1] + 1;
            } else {
                pre[i] = pre[i-1];
                posOfCandles.emplace_back(i-1);
            }
        }
        int q = (int)queries.size();
        vector<int> ans(q);
        int l, r, leftMost, rightMost;
        for (int i = 0; i < q; ++i) {
            l = queries[i][0];
            r = queries[i][1];
            auto iter = lower_bound(posOfCandles.begin(),posOfCandles.end(),l);
            if (iter == posOfCandles.end() || *iter > r) {
                ans[i] = 0;
                continue;
            }
            leftMost = *iter;
            iter = --upper_bound(posOfCandles.begin(),posOfCandles.end(),r);
            if (leftMost == *iter || *iter > r) {
                ans[i] = 0;
                continue;
            }
            rightMost = *iter;
            ++leftMost;
            ++rightMost;
            ans[i] = pre[rightMost] - pre[leftMost-1];
        }
        
        return ans;
    }
};