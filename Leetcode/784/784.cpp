class Solution {
public:
    vector<string> ans;
    void dfs(string &s, int index, string str) {
        if (index >= (int)s.size()) {
            ans.emplace_back(str);
            return;
        }
        if (isalpha(s[index])) {
            str.push_back(toupper(s[index]));
            dfs(s, index+1, str);
            str.pop_back();
            str.push_back(tolower(s[index]));
            dfs(s, index+1, str);
        } else {
            str.push_back(s[index]);
            dfs(s, index+1, str);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>().swap(ans);
        dfs(s, 0, string());
        return ans;
    }
};