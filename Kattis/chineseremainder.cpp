// https://open.kattis.com/problems/chineseremainder
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
    (!b) ? (x = 1, y = 0, g = a) : (exgcd(b, a % b, g, y, x), y -= x * (a / b));
}

int main() {

    ll t, a, n, b, m;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld %lld %lld", &a, &n, &b, &m);
        ll x, y, g;
        exgcd(m, -n, g, x, y);
        x = (x * (a - b) / g % (-n / g) - n / g) % (-n / g);
        printf("%lld %lld\n", ((x * m + b) % (n * m) + n * m) % (n * m), n * m);
    }

    return 0;
}
