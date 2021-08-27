class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        bool isPrime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0};
        int counter = 0;
        for (int i = L; i <= R; ++i) {
            if (isPrime[__builtin_popcount(i)]) {
                ++counter;
            }
        }
        return counter;
    }
};