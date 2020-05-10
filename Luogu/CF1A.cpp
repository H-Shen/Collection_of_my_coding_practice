#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n, m, a;
    scanf("%lld %lld %lld", &n, &m, &a);
    ll N, M;
    if (n <= a) {
        N = 1;
    } else if (n % a == 0) {
        N = n / a;
    } else {
        N = n / a + 1;
    }
    if (m <= a) {
        M = 1;
    } else if (m % a == 0) {
        M = m / a;
    } else {
        M = m / a + 1;
    }
    printf("%lld\n", N * M);

    return 0;
}