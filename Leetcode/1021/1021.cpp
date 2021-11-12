class Solution {
public:
    string removeOuterParentheses(string s) {
        constexpr int MAXN = 1e5+5;
        int leftBrackets = 0;
        int n = (int)s.size();
        int l = 0, r = 0;
        string ans;
        bitset<MAXN> bs;
        for (int i = 0; i < n; ++i) {
            if (leftBrackets == 0) {
                l = i;
            }
            if (s[i] == '(') {
                ++leftBrackets;
            } else {
                --leftBrackets;
                // balance
                if (leftBrackets == 0) {
                    r = i;
                    bs[l] = true;
                    bs[r] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!bs[i]) ans.push_back(s[i]);
        }
        return ans;
    }
};