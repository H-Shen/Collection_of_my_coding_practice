class Solution {
public:
    int minimizedStringLength(string s) {
        constexpr int MAXN = 26;
        bitset<MAXN> bs;
        int cnt = 0;
        for (const auto&i : s) {
            if (!bs[i - 'a']) {
                bs[i - 'a'] = true;
                ++cnt;
            }
        }
        return cnt;
    }
};