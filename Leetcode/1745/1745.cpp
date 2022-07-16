constexpr int MAXN = 2005;

bitset<MAXN> isPalindrome[MAXN];
bitset<MAXN> dp;


class Solution {
public:
    bool checkPartitioning(string s) {
        for (auto&i : isPalindrome) {
            i.reset();
        }
        int n = (int)s.size();
        // odd
        int l, r;
        for (int i = 0; i < n; ++i) {
            l = i;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                isPalindrome[l][r] = true;
                --l;
                ++r;
            }
        }
        // even
        for (int i = 1; i < n; ++i) {
            l = i-1;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                isPalindrome[l][r] = true;
                --l;
                ++r;
            }
        }
        // if s[i]...s[n-1] can be split into two palindrome substrings, dp[i] = true, otherwise dp[i] = false
        dp.reset();
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (isPalindrome[i][j-1] && isPalindrome[j][n-1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n-1; ++i) {
            if (isPalindrome[0][i] && dp[i+1]) {
                return true;
            }
        }
        return false;
    }
};