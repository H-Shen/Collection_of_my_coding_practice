constexpr int MAXN = 26;

class Solution {
public:
    bitset<MAXN> convert(string& s) {
        bitset<MAXN> bs;
        for (auto&ch : s) {
            bs[ch - 'a'] = true;
        }
        return bs;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<bitset<MAXN>> unset;
        for (auto&i : startWords) unset.insert(convert(i));
        int counter = 0;
        for (auto&s : targetWords) {
            bitset<MAXN> bs(convert(s));
            for (int i = 0; i < MAXN; ++i) {
                if (bs[i]) {
                    bs[i] = false;
                    if (unset.count(bs) > 0) {
                        ++counter;
                        break;
                    }
                    bs[i] = true;
                }
            }
        }
        return counter;
    }
};