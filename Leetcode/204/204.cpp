class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;
        vector<bool> isNotPrime(n + 5);
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for (int i = 2; i < n + 5; ++i) {
            if (!isNotPrime[i]) {
                if (i > (n + 5) / i) {
                    continue;
                }
                for (int j = i * i; j < n + 5; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (!isNotPrime[i]) {
                ++counter;
            }
        }
        return counter;
    }
};