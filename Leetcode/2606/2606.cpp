constexpr int MAXN = 26;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // max-subsum
        int maxSubSum = 0;
        // dp[i] = max(dp[i-1] + w[i], w[i])
        // dp[0] = w[0];
        int w[MAXN];
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            w[ch-'a'] = 1+(int)(ch - 'a');
        }
        int length = (int)vals.size();
        for (int i = 0; i < length; ++i) {
            w[chars[i]-'a'] = vals[i];
        }
        int dp = w[s[0]-'a'];
        maxSubSum = max(maxSubSum, dp);
        int n = (int)s.size();
        for (int i = 1; i < n; ++i) {
            dp = max(dp + w[s[i]-'a'], w[s[i]-'a']);
            maxSubSum = max(dp, maxSubSum);
        }
        return maxSubSum;
    }
};