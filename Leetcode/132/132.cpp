constexpr int MAXN = 2005;
constexpr int INF = 0x3f3f3f3f;

bitset<MAXN> isPalindrome[MAXN];

int dp[MAXN][MAXN]; // the minimum cuts from i to j = dp[i][j]

int solve(int i, int j) {
    if (dp[i][j] != INF) {
        return dp[i][j];
    }
    if (isPalindrome[i][j]) {
        dp[i][j] = 1;
        return dp[i][j];
    }
    for (int pos = i; pos < j; ++pos) {
        if (isPalindrome[i][pos]) {
            dp[i][j] = min(dp[i][j], 1+solve(pos+1,j));
        }   
    }
    return dp[i][j];
}

class Solution {
public:
    int minCut(string s) {
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
        if (n > 1) {
            for (int i = 1; i < n; ++i) {
                l = i-1;
                r = i;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    isPalindrome[l][r] = true;
                    --l;
                    ++r;
                }
            } 
        }
        // dp
        memset(dp, 0x3f, sizeof dp);
        return solve(0, n-1)-1;
    }
};