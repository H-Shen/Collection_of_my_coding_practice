class Solution {
public:
    bool isSubstringPresent(string s) {
        if (s.size() < 2) return false;
        int n = (int)s.size();
        for (int i = 0; i < n-1; ++i) {
            bool flag = false;
            for (int j = n-1; j > 0; --j) {
                if (s[j] == s[i] && s[j-1] == s[i+1]) {
                    flag = true;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};