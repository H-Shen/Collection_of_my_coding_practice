constexpr int MAXN = 26;

class Solution {
public:
    char repeatedCharacter(string s) {
        int freq[MAXN]{};
        for (auto&ch : s) {
            ++freq[ch - 'a'];
            if (freq[ch - 'a'] == 2) {
                return ch;
            }
        }
        return 0;
    }
};