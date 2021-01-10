class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        constexpr int MAXN = 26;
        bitset<MAXN> vis;
        for (const auto &ch : allowed) {
            vis[ch - 'a'] = true;
        }
        return count_if(words.begin(), words.end(), [&](const string &s) {
            for (const char &ch : s) {
                if (!vis[ch - 'a']) {
                    return false;
                }
            }
            return true;
        });
    }
};