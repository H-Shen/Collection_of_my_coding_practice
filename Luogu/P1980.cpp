#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n;
    ll x;
    ll i_copy;
    ll temp;
    ll counter = 0;
    scanf("%lld %lld", &n, &x);
    for (ll i = 1; i <= n; ++i) {
        i_copy = i;
        while (i_copy > 0) {
            temp = i_copy % 10;
            if (temp == x) {
                ++counter;
            }
            i_copy /= 10;
        }
    }
    printf("%lld\n", counter);
    return 0;
}