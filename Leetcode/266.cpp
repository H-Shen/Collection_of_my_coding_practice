class Solution {
public:
    bool canPermutePalindrome(string s) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const auto &i : s) {
            ++stats[i - 'a'];
        }
        int counter = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] % 2 != 0) {
                ++counter;
                if (counter > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};