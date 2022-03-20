constexpr int MAXN = 12;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int tot = 1<<MAXN;
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
        vector<int> bobArrows(MAXN);
        sum = numArrows;
        for (int j = 0; j < MAXN; ++j) {
            if (result[j]) {
                bobArrows[j] = aliceArrows[j]+1;
                sum -= bobArrows[j];
            }
        }
        if (sum > 0) {
            bobArrows[0] = sum;
        }
        return bobArrows;
    }
};