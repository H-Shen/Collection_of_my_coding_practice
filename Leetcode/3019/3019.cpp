class Solution {
public:
    int countKeyChanges(string s) {
        for (auto&i : s) {
            i = tolower(i);
        }
        int ans = 0;
        int n = (int)s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i-1]) ++ans;
        }
        return ans;
    }
};