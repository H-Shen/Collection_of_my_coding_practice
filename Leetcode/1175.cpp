constexpr long long MOD = 1000000007;

class Solution {
public:
    long long factorial(long long n) {
        long long result = 1;
        for (long long i = 1; i <= n; ++i) {
            result = (result* i) % MOD;
        }
        return result;
    }
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int c1 = 0;
        int c2 = 0;
        for (int i = 1; i <= n; ++i) {
            if (isPrime(i)) {
                ++c1;
            } else {
                ++c2;
            }
        }
        long long result = (factorial(c1) % MOD * factorial(c2) % MOD) % MOD;
        return result;
    }
};