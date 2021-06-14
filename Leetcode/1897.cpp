class Solution {
public:
    bool makeEqual(vector<string>& words) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const auto &i : words) {
            for (const auto &j : i) {
                ++stats[j - 'a'];
            }
        }
        int n = (int)words.size();
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] > 0) {
                if (stats[i] % n != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};