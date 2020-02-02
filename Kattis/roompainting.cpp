// https://open.kattis.com/problems/roompainting
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

vector<ll> paint_can_sizes;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    paint_can_sizes.resize(n);
    for (auto &i : paint_can_sizes) {
        scanf("%lld", &i);
    }
    sort(paint_can_sizes.begin(), paint_can_sizes.end());
    ll buy = 0;
    ll need = 0;
    ll val;
    while (m--) {
        scanf("%lld", &val);
        need += val;
        buy += *lower_bound(paint_can_sizes.begin(), paint_can_sizes.end(), val);
    }
    printf("%lld\n", buy - need);

    return 0;
}
