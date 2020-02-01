// https://open.kattis.com/problems/movingday
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    ll v;
    ll max_volumn = -1;
    ll a;
    ll b;
    ll c;
    scanf("%d %lld", &n, &v);
    while (n--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        max_volumn = max(max_volumn, a * b * c);
    }
    printf("%lld\n", max_volumn - v);

    return 0;
}
