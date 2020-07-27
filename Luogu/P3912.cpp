// Calculate the number of primes from 1 to n
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 100000005;

bitset<MAXN> is_not_prime;
ll count_primes(ll n) {
    if (n < 2) {
        return 0;
    }
    ll number_of_primes = n - 1;
    for (ll p = 2, i; p * p <= n; ++p) {
        if (!is_not_prime[p]) {
            i = p * p;
            while (i <= n) {
                if (!is_not_prime[i]) {
                    is_not_prime[i] = true;
                    --number_of_primes;
                }
                i += p;
            }
        }
    }
    return number_of_primes;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n;
    cin >> n;
    cout << count_primes(n) << '\n';
    return 0;
}
