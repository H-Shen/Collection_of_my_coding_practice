class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return string();
        }
        return accumulate(strs.begin(), strs.end(), strs[0], [](const string &a, const string &b) {
            string res;
            if (a.empty() || b.empty()) {
                return res;
            }
            int len = (int) min(a.size(), b.size());
            for (int i = 0; i < len; ++i) {
                if (a[i] == b[i]) {
                    res += a[i];
                } else {
                    break;
                }
            }
            return res;
        });
    }
};