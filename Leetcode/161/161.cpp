class Solution {
public:
    bool f(string &a, string &b) {
        int lena = (int)a.size();
        int lenb = (int)b.size();
        int i;
        for (i = 0; i < lenb; ++i) {
            if (a[i] != b[i]) {
                break;
            }
        }
        ++i;
        for (; i < lena; ++i) {
            if (a[i] != b[i-1]) {
                return false;
            }
        }
        return true;
    }
    bool isOneEditDistance(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        if (n == m) {
            int diff = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    ++diff;
                    if (diff > 1) {
                        break;
                    }
                }
            }
            return diff == 1;
        }
        else if (m == n - 1) {
            return f(s, t);
        }
        else if (n == m - 1) {
            return f(t, s);
        }
        return false;
    }
};