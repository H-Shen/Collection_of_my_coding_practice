class Solution {
public:
    vector<int> evenOddBit(int n) {
        constexpr int MAXN = 35;
        bitset<MAXN> bs(n);
        int c1 = 0, c2 = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (bs[i]) {
                if (i & 1) ++c1;
                else ++c2;
            }
        }
        return vector<int>{c2,c1};
    }
};