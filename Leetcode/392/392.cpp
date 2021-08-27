class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        auto iter = s.begin();
        for (const auto &i : t) {
            if (iter == s.end()) return true;
            if (i == *iter) {
                ++iter;
            }
        }
        return (iter == s.end());
    }
};