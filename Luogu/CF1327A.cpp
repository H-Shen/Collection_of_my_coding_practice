#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll t, n, k;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &n, &k);
        if (n >= k && n >= k * k && (n % 2) == (k % 2)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}