#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

ll solve(const ll &n) {
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return n / i;
        }
    }
    return 1;
}

int main() {

    int t;
    scanf("%d", &t);
    ll n, temp;
    while (t--) {
        scanf("%lld", &n);
        if (n & 1) {
            temp = solve(n);
            printf("%lld %lld\n", temp, n - temp);
        } else {
            n >>= 1;
            printf("%lld %lld\n", n, n);
        }
    }

    return 0;
}