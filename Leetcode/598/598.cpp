class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // diff array
        vector<int> row_diff(m+1);
        vector<int> col_diff(n+1);
        for (const auto &i : ops) {
            ++row_diff[0];
            --row_diff[i[0]];
            ++col_diff[0];
            --col_diff[i[1]];
        }
        // restore
        vector<int> row_pre(m);
        row_pre[0] = row_diff[0];
        for (int i = 1; i < m; ++i) {
            row_pre[i] = row_pre[i-1] + row_diff[i];
        }
        vector<int> col_pre(n);
        col_pre[0] = col_diff[0];
        for (int i = 1; i < n; ++i) {
            col_pre[i] = col_pre[i-1] + col_diff[i];
        }
        int maxVal = *max_element(row_pre.begin(),row_pre.end());
        maxVal = max(maxVal, *max_element(col_pre.begin(),col_pre.end()));
        return count(row_pre.begin(),row_pre.end(),maxVal) * count(col_pre.begin(),col_pre.end(),maxVal);
    }
};