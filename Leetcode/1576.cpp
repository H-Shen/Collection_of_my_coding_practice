class Solution {
public:
    string modifyString(string s) {
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                if (i == 0) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch != s[i+1]) {
                            s[i] = ch;
                            break;
                        }
                    }
                }
                else if (i == n - 1) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch != s[i-1]) {
                            s[i] = ch;
                            break;
                        }
                    }
                }
                else {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch != s[i-1] && ch != s[i+1]) {
                            s[i] = ch;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};