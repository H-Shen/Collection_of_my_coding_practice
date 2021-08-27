class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const char &ch : chars) {
            ++stats[ch - 'a'];
        }
        int counter = 0;
        bool haveAns;
        for (const auto &str : words) {
            haveAns = true;
            int stats_words[MAXN]{};
            for (const char &ch : str) {
                ++stats_words[ch - 'a'];
            }
            for (int i = 0; i < MAXN; ++i) {
                if (stats_words[i] > stats[i]) {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) counter += (int)str.size();
        }
        return counter;
    }
};