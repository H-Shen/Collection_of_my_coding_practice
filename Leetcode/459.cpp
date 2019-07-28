class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        auto repeatString = [](const string &s, int n) -> string {
            string result;
            for (int i = 0; i < n; ++i) {
                result += s;
            }
            return result;
        };

        int len = static_cast<int>(unordered_set<char>(s.begin(), s.end()).size());
        int l = static_cast<int>(s.size());
        if (l == len) {
            return false;
        }
        for (int i = 1; i <= l / 2; ++i) {
            if (repeatString(s.substr(0, static_cast<unsigned long>(i)), l / i) == s) {
                return true;
            }
        }
        return false;
    }
};