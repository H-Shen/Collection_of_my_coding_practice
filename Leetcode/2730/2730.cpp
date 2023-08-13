class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        auto check = [&](const int &l, const int &r) {
            if (l == r) return false;
            int cnt = 0;
            for (int i = l; i < r; ++i) {
                if (s[i] == s[i+1]) ++cnt;
                if (cnt > 1) return false;
            }
            return true;
        };
        int ans = 1;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >= i; --j) {
                if (j-i+1<ans) break;
                if (check(i,j)) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};