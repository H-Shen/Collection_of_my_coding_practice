#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int t;
    ll a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld\n", (a + b + c) / 2);
    }

    return 0;
}