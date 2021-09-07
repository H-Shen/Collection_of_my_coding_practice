constexpr int MAXN = 26;
constexpr int N = 1e5+5;

int pre[N][MAXN];

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        memset(pre, 0, sizeof pre);
        int n = (int)s.size();
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                pre[i][j] = pre[i-1][j];
            }
            ++pre[i][s[i-1] - 'a'];
        }
        int q = (int)queries.size();
        vector<bool> ans(q);
        int l, r, k, odd;
        int stats[MAXN];
        for (int i = 0; i < q; ++i) {
            l = queries[i][0]+1;
            r = queries[i][1]+1;
            k = queries[i][2];
            odd = 0;
            for (int j = 0; j < MAXN; ++j) {
                stats[j] = pre[r][j] - pre[l-1][j];
                if (stats[j] & 1) {
                    ++odd;
                }
            }
            if (odd <= 1) {
                ans[i] = true;
            }
            else {
                ans[i] = (odd & 1) ? ((odd-1) >> 1) <= k : (odd >> 1) <= k;
            }
        }
        return ans;
    }
};