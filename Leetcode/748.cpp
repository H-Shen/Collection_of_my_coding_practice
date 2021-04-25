class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        constexpr int MAXN = 26;
        int unmap[MAXN]{};
        for (const auto &i : licensePlate) {
            if (isalpha(i)) {
                ++unmap[tolower(i) - 'a'];
            }
        }
        size_t minLength = 0x3f3f3f3f;
        int position = 0;
        int n = (int)words.size();
        bool haveAns;
        for (int i = 0; i < n; ++i) {
            int stats[MAXN]{};
            for (const auto &ch : words[i]) {
                ++stats[ch - 'a'];
            }
            haveAns = true;
            for (int j = 0; j < MAXN; ++j) {
                if (unmap[j] > stats[j]) {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) {
                if (words[i].size() < minLength) {
                    minLength = words[i].size();
                    position = i;
                }
            }
        }
        return words[position];
    }
};