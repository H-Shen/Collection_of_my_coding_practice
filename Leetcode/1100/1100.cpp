class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        int n = (int)s.size();
        if (k > n) {
            return 0;
        }
        int counter = 0;
        int i;
        for (i = 0; i < k; ++i) {
            ++stats[s[i] - 'a'];
        }
        --i;
        bool dup;
        while (true) {
            dup = false;
            for (int j = 0; j < MAXN; ++j) {
                if (stats[j] > 1) {
                    dup = true;
                    break;
                }
            }
            if (!dup) {
                ++counter;
            }
            ++i;
            if (i >= n) {
                break;
            }
            ++stats[s[i] - 'a'];
            --stats[s[i-k] - 'a'];
        }
        return counter;
    }
};