class Solution {
public:
    bool isNice(const string &s, int startIndex, int endIndex) {
        constexpr int MAXN = 26;
        constexpr int MAX_TYPES = 2;
        bitset<MAX_TYPES> vis[MAXN];    // 0 for lowercase, 1 for uppercase
        for (int i = startIndex; i <= endIndex; ++i) {
            if (isupper(s[i])) {
                vis[s[i] - 'A'][1] = true;
            }
            else if (islower(s[i])) {
                vis[s[i] - 'a'][0] = true;
            }
        }
        for (int i = 0; i < MAXN; ++i) {
            if ( (vis[i][0] && !vis[i][1]) || (!vis[i][0] && vis[i][1]) ) {
                return false;
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        if (s.size() <= 1) return string();
        int n = (int)s.size();
        int maxLength = 0;
        int startIndex = -1;
        int endIndex = -1; 
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isNice(s, i, j)) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        startIndex = i;
                        endIndex = j;
                    }
                }
            }
        }
        if (startIndex == -1) {
            return string();
        }
        return s.substr(startIndex, maxLength);
    }
};