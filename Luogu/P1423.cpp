#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-7;
inline int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {

    double x;
    scanf("%lf", &x);
    int counter = 0;
    double speed = 2.0;
    while (true) {
        x -= speed;
        speed *= 0.98;
        ++counter;
        if (sgn(x) <= 0) {
            break;
        }
    }
    printf("%d\n", counter);
    return 0;
}
