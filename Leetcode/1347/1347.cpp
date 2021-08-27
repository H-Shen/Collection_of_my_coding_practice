class Solution {
public:
    int minSteps(string s, string t) {
        constexpr int MAXN = 26;
        int stats_s[MAXN]{};
        int stats_t[MAXN]{};
        for (const char &ch : s) ++stats_s[ch - 'a'];
        for (const char &ch : t) ++stats_t[ch - 'a'];
        int steps = 0;
        // change s to t
        int n = (int)s.size();
        for (int i = 0; i < MAXN; ++i) {
            if (stats_s[i] > stats_t[i]) {
                steps += stats_s[i] - stats_t[i];
            }
        }
        return steps;
    }
};