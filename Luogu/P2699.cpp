#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

__int128 l, r, w;

int main() {

    ll l_ll, r_ll, w_ll;
    scanf("%lld %lld %lld", &l_ll, &r_ll, &w_ll);
    l = l_ll;
    r = r_ll;
    w = w_ll;
    __int128 power = 1;
    bool first_item = true;
    unordered_set<ll> unset;
    while (true) {
        if (power >= l && power <= r) {
            if (first_item) {
                first_item = false;
            } else {
                putchar_unlocked(' ');
            }
            printf("%lld", static_cast<ll>(power));
        }
        unset.insert(power);
        power *= w;
        if (unset.find(power) != unset.end()) {
            break;
        }
        if (power > r) {
            break;
        }
    }
    if (first_item) {
        printf("-1");
    }
    putchar_unlocked('\n');


    return 0;
}