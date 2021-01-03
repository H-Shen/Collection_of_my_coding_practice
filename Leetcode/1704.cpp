class Solution {
public:
    bool halvesAreAlike(const string &s) {
        constexpr int MAXN = 128;
        bitset<MAXN> vowel;
        vowel['a'] = true;
        vowel['e'] = true;
        vowel['i'] = true;
        vowel['o'] = true;
        vowel['u'] = true;
        vowel['A'] = true;
        vowel['E'] = true;
        vowel['I'] = true;
        vowel['O'] = true;
        vowel['U'] = true;
        return count_if(s.begin(), s.begin() + s.size() / 2, [&](char ch){return vowel[ch];}) == count_if(s.begin() + s.size() / 2, s.end(), [&](char ch){return vowel[ch];});
    }
};