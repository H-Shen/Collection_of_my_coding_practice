#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n;
    scanf("%lld", &n);
    ll sum = 0;
    ll days = 1;
    ll counter = 0;
    while (true) {
        for (ll i = 1; i <= days; ++i) {
            sum += days;
            ++counter;
            if (counter == n) {
                printf("%lld\n", sum);
                return 0;
            }
        }
        ++days;
    }
    return 0;
}
