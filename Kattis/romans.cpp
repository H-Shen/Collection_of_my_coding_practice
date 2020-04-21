// https://open.kattis.com/problems/romans
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    double x;
    scanf("%lf", &x);
    x = x * 1000.0 * 5280.0 / 4854.0;
    printf("%d\n", static_cast<int>(lround(x)));
    return 0;
}
