// https://open.kattis.com/problems/shatteredcake
//

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ll W;
    scanf("%lld", &W);
    int n;

    ll S = 0;
    ll w, l;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld %lld", &w, &l);
        S += w * l;
    }

    printf("%lld\n", S / W);
    return 0;
}
