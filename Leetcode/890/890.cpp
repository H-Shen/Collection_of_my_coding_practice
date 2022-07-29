class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = (int)pattern.size();
        for (auto&word : words) {
            unordered_map<char, char> m, mRev;
            bool haveAns = true;
            int a, b;
            for (int i = 0; i < n; ++i) {
                a = (int)m.count(word[i]);
                b = (int)mRev.count(pattern[i]);
                if (a == 0 && b == 0) {
                    m[word[i]] = pattern[i];
                    mRev[pattern[i]] = word[i];
                }
                else if (a > 0 && b > 0 && m[word[i]] == pattern[i] && mRev[pattern[i]] == word[i]) {
                    continue;
                }
                else {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};