class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        constexpr int MAXN = 50;
        int stats[MAXN]{};
        int i_copy, sum;
        for (int i = lowLimit; i <= highLimit; ++i) {
            sum = 0;
            i_copy = i;
            while (i_copy > 0) {
                sum += i_copy % 10;
                i_copy /= 10;
            }
            ++stats[sum];
        }
        return *max_element(stats, stats + MAXN);
    }
};