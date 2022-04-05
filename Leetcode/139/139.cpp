// DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        int n = (int)s.size();
        vector<bool> dp(n+1); // dp[i] = if s[0:i] can be segmented into a space-separated sequence of one or more dictionary words
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && words.count(s.substr(j, i-j)) > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// DFS TLE
class Solution1 {
public:
    bool haveAns;
    void dfs(string&s, int index, int n, unordered_set<string>& words) {
        if (haveAns) {
            return;
        }
        if (index == n) {
            haveAns = true;
            return;
        }
        string str;
        for (int i = index; i < n; ++i) {
            if (haveAns) {
                return;
            }
            str.push_back(s[i]);
            if (words.count(str) > 0) {
                dfs(s, i+1, n, words);
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        haveAns = false;
        string str;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (haveAns) {
                break;
            }
            str.push_back(s[i]);
            if (words.count(str) > 0) {
                dfs(s, i+1, n, words);
            }
        }
        return haveAns;
    }
};