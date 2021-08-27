class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> A = {1,9,9*9,9*9*8,9*9*8*7,9*9*8*7*6,9*9*8*7*6*5,9*9*8*7*6*5*4,9*9*8*7*6*5*4*3,9*9*8*7*6*5*4*3*2};
        int counter = 0;
        for (int i = 0; i <= n; ++i) {
            counter += A[i];
        }
        return counter;
    }
};