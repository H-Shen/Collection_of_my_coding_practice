class Solution {
public:
    bool check(const string &a, const string &b) {
        int n = (int)a.size();
        int m = (int)b.size();
        if (n < m) return false;
        int i, j;
        for (i = 0, j = 0; i < n && j < m; ++i) {
            if (a[i] == b[j]) {
                ++j;
            }
        }
        return (j == m);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        constexpr int MAXN = 1e5+5;
        bitset<MAXN> upd;
        int ret = 0;
        int mid;
        int start = 0;
        int end = (int)removable.size()-1;
        int n = (int)s.size();
        while (start <= end) {
            mid = start + ((end - start) >> 1);
            for (int i = 0; i <= mid; ++i) {
                upd[removable[i]] = true;
            }
            string strAfterFilter;
            for (int i = 0; i < n; ++i) {
                if (!upd[i]) {
                    strAfterFilter.push_back(s[i]);
                }
            }
            if (check(strAfterFilter, p)) {
                ret = mid + 1;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            upd.reset();
        }
        return ret;
    }
};