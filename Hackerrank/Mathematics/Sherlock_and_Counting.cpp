#include <cmath>
#include <cstdio>

typedef long long ll;

int main() {

    int q;
    ll n, k, gap;
    ll res;
    scanf("%d", &q);

    while (q--) {

        res = 0;
        scanf("%lld %lld", &n, &k);
        gap = n * n - 4 * k * n;

        if (gap <= 0) {
            res = n - 1;
        }
        else {
            ll tmp = (ll)sqrt((double)gap);
            if (tmp * tmp == gap) {

                if ( (tmp + n) % 2 == 0) {
                    res = res + (n - tmp) / 2;
                    res = res + n - (tmp + n) / 2;
                }
                else {
                    res = res + (ll)((tmp - n) / 2.0);
                    res = res + n - (ll)((tmp + n) / 2.0) - 1;
                }
            }
            else {
                res = res + (ll)(( n - sqrt((double)gap )) / 2.0);
                res = res + n - (ll)(( n + sqrt((double)gap )) / 2.0) - 1;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
