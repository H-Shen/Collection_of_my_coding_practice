// https://open.kattis.com/problems/relatives
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

ll euler_phi(ll n) {
    if (n == 1) {
        return 0;
    }
    ll m = sqrt(n + 0.5);
    ll ans = n;
    for (ll i = 2; i <= m; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main() {

    ll n;
    while (true) {
        scanf("%lld", &n);
        if (n == 0) {
            break;
        }
        printf("%lld\n", euler_phi(n));
    }

    return 0;
}
