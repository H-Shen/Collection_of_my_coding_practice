class Solution {
public:
    bool checkString(string s) {
        int n = (int)s.size();
        bool hasB = false;
        for (int i = 0; i < n; ++i) {
            if (hasB && s[i] == 'a') return false;
            if (s[i] == 'b') hasB = true;
        }
        return true;
    }
};