#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAX = 100000005;
constexpr int MAX_PRIMES = 5761457;
int prime[MAX_PRIMES] = {0};
int num_prime = 0;
bool isNotPrime[MAX] = {true, true};

/**
 * A linear sieve algorithm for finding prime numbers from 2-MAX
 */
void init() {
    for (int i = 2; i < MAX; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < MAX; j++) {
            isNotPrime[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main() {
    init();
    int n, q, k;
    scanf("%d %d", &n, &q);
    while (q--) {
        scanf("%d", &k);
        printf("%d\n", prime[k - 1]);
    }
    return 0;
}
