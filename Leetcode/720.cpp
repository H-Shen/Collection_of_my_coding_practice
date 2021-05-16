class Solution {
public:
    bool check(string s, const unordered_set<string> &dict) {
        s.pop_back();
        while (!s.empty()) {
            if (dict.find(s) == dict.end()) {
                return false;
            }
            s.pop_back();
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        bool haveAns = false;
        string ans;
        for (const auto &s : dict) {
            if (check(s, dict)) {
                if (!haveAns) {
                    haveAns = true;
                    ans = s;
                }
                else {
                    if (s.size() > ans.size() || (s.size() == ans.size() && s < ans)) {
                        ans = s;
                    }
                }
            }
        }
        return ans;
    }
};