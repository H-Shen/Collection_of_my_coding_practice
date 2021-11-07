using ll = long long;
constexpr int MAXN = 1e5+5;
ll dp[MAXN];

class Solution {
public:
    long long countVowels(string word) {
        int n = (int)word.size();
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; ++i) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                if (i == 0) {
                    dp[i] = 1;
                }
                else {
                    dp[i] = dp[i-1] + (i+1);
                }
            }
            else if (i > 0) {
                dp[i] = dp[i-1];
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dp[i];
        }
        return ans;
    }
};