class Solution {
public:
    int binaryGap(int n) {
        constexpr size_t MAXN = 32;
        bitset<MAXN> bs(n);
        int maxDist = 0;
        int last = -1;
        for (size_t i = bs._Find_first(); i < MAXN; i = bs._Find_next(i)) {
            if (last == -1) {
                last = (int)i;
            }
            else {
                maxDist = max(maxDist, (int)i - last);
                last = (int)i;
            }
        }
        return maxDist;
    }
};