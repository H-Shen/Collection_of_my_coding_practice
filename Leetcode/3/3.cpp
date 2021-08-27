class Solution {
public:
    vector<int> LongestSubarrayWithoutRepeatingIntegers(const string &s, int N) {
        vector<int> dp(N+1, 0);
        unordered_map<char, int> hashMap;   // hashMap[c] = the position of 'c' appears most recently
        for (int j = 1, i; j <= N; ++j) {
            // Base case:
            if (j == 1) {
                dp[j] = 1;
                hashMap[s[j-1]] = 1;  // Index starts from 1
                continue;
            }
            if (hashMap.find(s[j]) == hashMap.end()) {
                dp[j] = dp[j-1] + 1;
            } else {
                i = hashMap[s[j]];
                if (dp[j-1] < j-i) {
                    dp[j] = dp[j-1] + 1;
                } else {
                    dp[j] = j-i;
                }
            }
            hashMap[s[j]] = j;
        }
        return dp;
    }
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        int N = (int)s.size();
        vector<int> dp = LongestSubarrayWithoutRepeatingIntegers(s, N);
        int result = 0;
        for (int i = 0; i < N; ++i) {
            result = max(result, dp[i]);
        }
        return result;
    }
};