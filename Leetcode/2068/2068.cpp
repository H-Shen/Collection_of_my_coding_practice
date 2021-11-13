class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        constexpr int MAXN = 26;
        int stats1[MAXN]{};
        for (auto&i : word1) ++stats1[i-'a'];
        int stats2[MAXN]{};
        for (auto&i : word2) ++stats2[i-'a'];
        for (int i = 0; i < MAXN; ++i) {
            if (abs(stats1[i]-stats2[i]) > 3) return false;
        }
        return true;
    }
};