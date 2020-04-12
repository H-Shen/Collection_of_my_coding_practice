#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll A = 0;
    ll B = 0;
    int n;
    ll val;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &val);
        A += val;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &val);
        B += val;
    }
    printf("%.6lf\n", static_cast<double>(3*A-2*B)*1.0/(1.0*(A-B)));

    return 0;
}
