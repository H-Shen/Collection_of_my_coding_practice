// https://www.nowcoder.com/practice/c3b34059faf546d3a7ee28f2b0154286

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll quickJoseph(ll n, ll m, ll s = 1) {

    if (m == 1)
        return (n - 1 + s) % n;
    ll res = 0;

    for (ll i = 2; i <= n;) {
        if (res + m < i) {
            ll leap;
            if ((i - res - 1) % (m - 1) == 0)
                leap = (i - res - 1) / (m - 1) - 1;
            else
                leap = (i - res - 1) / (m - 1);
            if (i + leap > n)
                return ((res + (n + 1 - i) * m) + s) % n;
            i += leap;
            res += leap * m;
        } else {
            res = (res + m) % i;
            i++;
        }
    }
    return (res + s) % n;
}

int main() {

    ll n, m;
    while (~scanf("%lld %lld", &n, &m)) {
        ll res = quickJoseph(n, m);
        if (res == 0)
            printf("%lld\n", n);
        else
            printf("%lld\n", res);
    }
    return 0;
}
