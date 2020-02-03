// https://open.kattis.com/problems/toys
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

ll quickJoseph(ll n, ll k, ll s = 1) {

    if (k == 1)
        return (n - 1 + s) % n;
    ll res = 0;

    for (ll i = 2; i <= n;) {
        if (res + k < i) {
            ll leap;
            if ((i - res - 1) % (k - 1) == 0)
                leap = (i - res - 1) / (k - 1) - 1;
            else
                leap = (i - res - 1) / (k - 1);
            if (i + leap > n)
                return ((res + (n + 1 - i) * k) + s) % n;
            i += leap;
            res += leap * k;
        } else {
            res = (res + k) % i;
            i++;
        }
    }
    return (res + s) % n;
}

int main() {

    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll res = quickJoseph(n, k);
    if (res == 0)
        printf("%lld\n", n - 1);
    else
        printf("%lld\n", res - 1);
    return 0;

}
