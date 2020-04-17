#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ld = long double;

int main() {

    ld a;
    __float128 sum = 0.0;
    while (~scanf("%Lf", &a)) {
        sum += a;
    }
    printf("%.5Lf\n", static_cast<ld>(sum));

    return 0;
}
