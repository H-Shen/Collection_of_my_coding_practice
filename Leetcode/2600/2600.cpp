class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        while (k--) {
            if (numOnes > 0) {
                ++sum;
                --numOnes;
            }
            else if (numZeros > 0) {
                --numZeros;
            }
            else if (numNegOnes > 0) {
                --sum;
                --numNegOnes;
            }
        }
        return sum;
    }
};