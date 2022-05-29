constexpr int MAXN = 26;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int freq[MAXN]{};
        for (auto& ch : s) ++freq[ch - 'a'];
        int counter = 0;
        while (true) {
            for (auto& ch : target) {
                if (freq[ch - 'a'] == 0) {
                    return counter;
                }
                --freq[ch - 'a'];
            }
            ++counter;
        }
        return counter;
    }
};