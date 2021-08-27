class Solution {
public:
    int countLargestGroup(int n) {
        constexpr int MAXN = 40;
        int freq[MAXN]{};
        int iCopy, sum;
        for (int i = 1; i <= n; ++i) {
            sum = 0;
            iCopy = i;
            while (iCopy > 0) {
                sum += iCopy % 10;
                iCopy /= 10;
            }
            ++freq[sum];
        }
        int maxVal = *max_element(freq, freq + MAXN);
        return count(freq, freq + MAXN, maxVal);
    }
};