class Solution {
public:
    int secondHighest(string s) {
        int digit = -1;
        constexpr int MAXN = 10;
        bitset<MAXN> vis;
        for (const char &ch : s) {
            if (isdigit(ch)) {
                digit = ch - '0';
                vis[digit] = true;
            }
        }
        int counter = 0;
        for (int i = MAXN - 1; i >= 0; --i) {
            if (vis[i]) {
                ++counter;
                if (counter == 2) {
                    return i;
                }
            }
        }
        return -1;
    }
};