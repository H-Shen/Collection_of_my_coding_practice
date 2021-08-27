class Solution {
public:
    bool closeStrings(string word1, string word2) {
        constexpr int MAXN = 26;
        int stats1[MAXN]{};
        for (const char &ch : word1) {
            ++stats1[ch-'a'];
        }
        int stats2[MAXN]{};
        for (const char &ch : word2) {
            ++stats2[ch-'a'];
        }
        // must have the same freq
        unordered_map<int,int> freq1, freq2;
        for (int i = 0; i < MAXN; ++i) {
            if (stats1[i] > 0 && stats2[i] == 0) return false;
            if (stats1[i] == 0 && stats2[i] > 0) return false;
            if (stats1[i] > 0 && stats2[i] > 0) {
                ++freq1[stats1[i]];
                ++freq2[stats2[i]];
            }
        }
        return freq1 == freq2;
    }
};