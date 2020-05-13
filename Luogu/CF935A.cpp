#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

namespace EulerPrimeSieve {

    const int MAXN = 100005;
    int prime[MAXN] = {0};
    int num_prime = 0;
    bool isNotPrime[MAXN] = {true, true};

    // Generate the prime table from 1 to MAXN
    inline static
    void init() {
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = true;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
}

int main() {
    EulerPrimeSieve::init();
    int n;
    unordered_map<int, int, custom_hash> A;
    scanf("%d", &n);
    for (int i = 0; i < EulerPrimeSieve::num_prime; ++i) {
        while (n % EulerPrimeSieve::prime[i] == 0 && n >= EulerPrimeSieve::prime[i]) {
            ++A[EulerPrimeSieve::prime[i]];
            n /= EulerPrimeSieve::prime[i];
        }
        if (n == 1) {
            break;
        }
    }
    // Fundamental theorem of arithmetic
    ll ways = 1;
    for (const auto &[k, v] : A) {
        ways *= (v + 1);
    }
    printf("%lld\n", ways - 1);
    return 0;
}