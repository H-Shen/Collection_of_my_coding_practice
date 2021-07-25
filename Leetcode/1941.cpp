class Solution {
public:
    bool areOccurrencesEqual(string s) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const char &ch : s) ++stats[ch-'a'];
        int last = -1;
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] != 0) {
                if (last == -1) {
                    last = stats[i];
                }
                else if (last != stats[i]) {
                    return false;
                }
                last = stats[i];
            }
        }
        return true;
    }
};