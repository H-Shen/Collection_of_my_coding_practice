constexpr int MAXN = 26;
char freq[MAXN];

class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int n = (int)s.size();
        auto check = [&](int i, int j) {
            memset(freq, 0, sizeof freq);
            for (int pos = i; pos <= j; ++pos) {
                ++freq[s[pos] - 'a'];
                if (freq[s[pos] - 'a'] > 1) {
                    return false;
                }
            }
            return true;
        };
        int cnt = 0;
        int steps;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < MAXN && i+j < n; ++j) {
                if (check(i, i+j)) ++cnt;
                else break;
            }
        }
        return cnt;
    }
};