constexpr int MAXN = 12;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int tot = 1<<12;
        int maxVal = 0;
        int sum = 0;
        bitset<MAXN> result;
        for (int i = 1; i <= tot-1; ++i) {
            auto bs = bitset<MAXN>(i);
            sum = 0;
            for (int j = 0; j < MAXN; ++j) {
                if (bs[j]) {
                    sum += aliceArrows[j]+1;
                }
            }
            if (sum <= numArrows) {
                int temp = 0;
                for (int j = 0; j < MAXN; ++j) {
                    if (bs[j]) {
                        temp += j;
                    }
                }
                if (temp > maxVal) {
                    for (int j = 0; j < MAXN; ++j) {
                        result[j] = bs[j];
                    }
                    maxVal = temp;
                }
            }
        }
        vector<int> bob(12);
        sum = numArrows;
        for (int j = 0; j < MAXN; ++j) {
            if (result[j]) {
                bob[j] = aliceArrows[j]+1;
                sum -= bob[j];
            }
        }
        if (sum > 0) {
            bob[0] = sum;
        }
        return bob;
    }
};