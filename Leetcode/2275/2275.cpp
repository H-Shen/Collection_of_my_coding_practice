constexpr int MAXN = 31;

int counter[MAXN+5];

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        memset(counter, 0, sizeof counter);
        int currentBits;
        for (auto&i : candidates) {
            currentBits = MAXN;
            while (i > 0) {
                if (i & 1) {
                    ++counter[currentBits];
                }
                i >>= 1;
                --currentBits;
            }
        }
        return *max_element(counter, counter + MAXN + 5);
    }
};