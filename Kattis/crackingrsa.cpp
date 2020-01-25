// https://open.kattis.com/problems/crackingrsa
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr ll MAX = 1005;
ll prime[MAX] = {0};
ll num_prime = 0;
ll isNotPrime[MAX] = {1, 1};

/**
 * A linear sieve algorithm for finding prime numbers from 2-MAX
 */
void linearSieve() {
    for (ll i = 2; i < MAX; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (ll j = 0; j < num_prime && i * prime[j] < MAX; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

/**
 * An implementation of the extended Euclidean algorithm,
 * it obtains a pair solution (x0, y0) such that ax0 + by0 = gcd(a, b)
 * gcd(a, b) is returned as output, meanwhile the value of x and y are x0, y0 respectively.
 * @return gcd(a, b)
 */
ll exgcd(ll a, ll b, ll &x, ll &y) {

    // Case 1:
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // Case 2:
    ll gcdVal = exgcd(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp - a / b * y;
    return gcdVal;
}

int main() {

    // pre-process
    linearSieve();

    // input
    int t;
    ll p{};
    ll q{};
    ll phi_n, n, e, d, y, tempValue;

    scanf("%d", &t);
    while (t--) {

        scanf("%lld %lld", &n, &e);

        // Since we have all primes between 2-1000, we can obtain p and q by linear-check
        for (ll i = 0; i < num_prime; ++i) {
            p = prime[i];
            if (n % p == 0) {
                q = n / p;
                if (!isNotPrime[q]) {
                    break;
                }
            }
        }

        phi_n = (p - 1) * (q - 1);

        // d * e = e * d = 1 (mod phi_n) --> e * d - k * phi_n = 1 (for some integer k)
        // Let y be some integer such that y = -k, we have e * d + phi_n * y = 1
        // From the problem we know d exists and d is unique, thus
        // Extended Euclidean Algorithm can be used here to obtain d.
        tempValue = exgcd(e, phi_n, d, y);

        // Since d + k * phi_n (for all integers k) are possible values of d for e * d + phi_n * y = 1
        // We obtain the value of d such that 1 < d < phi_n
        while (d <= 1) {
            d += phi_n;
        }
        while (d >= phi_n) {
            d -= phi_n;
        }
        printf("%lld\n", d);
    }
    return 0;
}
