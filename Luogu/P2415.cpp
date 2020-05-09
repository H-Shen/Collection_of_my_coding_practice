#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll sum = 0;
    ll n = 0;
    ll val;
    while (~scanf("%lld", &val)) {
        sum += val;
        ++n;
    }
    if (n > 0) {
        printf("%lld\n", sum * static_cast<ll>(pow(2, n - 1)));
    } else {
        printf("0\n");
    }

    return 0;
}
