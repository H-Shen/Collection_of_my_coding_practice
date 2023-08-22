class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = (int)words.size();
        int m = (int)s.size();
        if (n != m) return false;
        for (int i = 0; i < n; ++i) {
            if (words[i][0] != s[i]) return false;
        }
        return true;
    }
};