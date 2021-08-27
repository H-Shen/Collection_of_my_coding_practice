class Solution {
public:
    bool isPalindrome(string s) {
        string s_filter;
        for (const auto &p : s) {
            if (isalnum(p)) {
                s_filter += tolower(p);
            }
        }
        string s_filter_copy = s_filter;
        reverse(s_filter.begin(), s_filter.end());
        return (s_filter_copy == s_filter);
    }
};