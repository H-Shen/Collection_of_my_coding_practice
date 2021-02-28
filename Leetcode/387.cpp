class Solution {
public:
    int firstUniqChar(string s) {
        constexpr int MAXN = 26;
        int freq[MAXN]{};
        for (const char &ch : s) {
            ++freq[ch - 'a'];
        }
        for (size_t i = 0; i != s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            } 
        }
        return -1;
    }
};