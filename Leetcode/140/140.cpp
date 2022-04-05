class Solution {
public:
    void dfs(vector<vector<string>>&result, vector<string>ans, vector<bool>&dp, int index, unordered_set<string> &dict, string s, string& original_string) {
        if (index == 0) {
            int length = 0;
            for (auto&j : ans) {
                length += (int)j.size();
            }
            int remaining = (int)original_string.size() - length;
            if (remaining > 0) {
                if (dict.count(original_string.substr(0, remaining)) > 0) {
                    ans.emplace_back(original_string.substr(0, remaining));
                }
                else {
                    return;
                }
            }
            if (!ans.empty()) {
                reverse(ans.begin(),ans.end());
                result.emplace_back(ans);
            }
            return;
        }
        if (dict.count(s.substr(index)) > 0 && dp[index]) {
            dfs(result, ans, dp, index-1, dict, s, original_string);
            ans.emplace_back(s.substr(index));
            dfs(result, ans, dp, index-1, dict, s.substr(0,index), original_string);
        }
        else {
            dfs(result, ans, dp, index-1, dict, s, original_string);
        }
    }
    // dp + dfs backtrack
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i-j)) > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        vector<vector<string>> result;
        dfs(result, vector<string>(), dp, n-1, dict, s, s);
        vector<string> answer;
        string temp;
        for (auto& i : result) {
            temp = i[0];
            for (int j = 1; j < (int)i.size(); ++j) {
                temp.push_back(' ');
                temp += i[j];
            }
            answer.emplace_back(temp);
        }
        return answer;
    }
};