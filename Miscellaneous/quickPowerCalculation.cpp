/**
 * An implementation of quick calculation of a^n / a^n(mod m)
 */
#include <cassert>

#define DEBUG

// Calculate a^n (n >= 0) in O(lgn) with recursion
inline static
long long quickPower(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    long long res{quickPower(a, n / 2)};
    if (n % 2) {
        return res * res * a;
    }
    return res * res;
}

// Calculate a^n (n >= 0) in O(lgn) without recursion
inline static
long long quickPowerWithoutRecursion(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

inline static
bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Calculate (a^n) % m (n >= 0, m > 0) in O(lgn) without recursion
inline static
long long quickPowerWithoutRecursion(long long a, long long n, long long m) {

    // If m is a prime, then (a^n) % m = a^(n % (m - 1)) % m (Fermat's little theorem)
    if (isPrime(m)) {
        n = n % (m - 1);
    }

    a %= m;
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int main() {

#ifdef DEBUG
    assert(quickPower(5, 22) == 2384185791015625);
    assert(quickPower(123123, 0) == 1);
    assert(quickPowerWithoutRecursion(5, 22) == 2384185791015625);
    assert(quickPowerWithoutRecursion(123123, 0) == 1);
    assert(quickPowerWithoutRecursion(5, 22, 1231) == 359);
    assert(quickPowerWithoutRecursion(31, 11, 121331112) == 92829847);
    assert(quickPowerWithoutRecursion(3, 17, 1231131) == 1102539);
#endif

    return 0;
}