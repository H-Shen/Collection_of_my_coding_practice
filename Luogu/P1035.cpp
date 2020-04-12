#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-7;
inline static
int sgn(double x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {

    double k;
    scanf("%lf", &k);
    double sum = 0.0;
    int n = 1;
    while (sgn(sum - k) <= 0) {
        sum += 1.0 / n;
        ++n;
    }
    printf("%d\n", n - 1);

    return 0;
}