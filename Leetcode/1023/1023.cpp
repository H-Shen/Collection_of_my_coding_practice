class Solution {
public:
    bool match(string& text, string& pattern) {
        auto iter = pattern.begin();
        for (auto &ch : text) {
            if (iter != pattern.end()) {
                if (ch == *iter) {
                    ++iter;
                }
                else if (isupper(ch)) {
                    return false;
                }
            }
            else {
                if (isupper(ch)) {
                    return false;
                }
            }
        }
        return iter == pattern.end();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = (int)queries.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = match(queries[i], pattern);
        }
        return ans;
    }
};