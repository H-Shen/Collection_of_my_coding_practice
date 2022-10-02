constexpr int MAXN = 33;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<MAXN> bs1(num1);
        bitset<MAXN> bs2(num2);
        int c1 = (int)bs1.count();
        int c2 = (int)bs2.count();
        if (c1 == c2) {
            return num1;
        }
        else if (c1 > c2) {
            bitset<MAXN> bs3;
            for (int i = MAXN-1; i >= 0 && c2 > 0; --i) {
                if (bs1[i]) {
                    bs3[i] = true;
                    --c2;
                }
            }
            return (int)bs3.to_ulong();
        }
        else {
            bitset<MAXN> bs3(num1);
            c2 -= c1;
            for (int i = 0; i < MAXN && c2 > 0; ++i) {
                if (!bs3[i]) {
                    bs3[i] = true;
                    --c2;
                }
            }
            return (int)bs3.to_ulong();
        }
    }
};