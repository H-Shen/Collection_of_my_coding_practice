#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double G = 10.0;

int main() {

    double v, theta;
    scanf("%lf %lf", &v, &theta);
    double x = v * v * cos(theta) * sin(theta) / G;
    double y = v * v * cos(theta) * cos(theta) / (2.0 * G);
    printf("%.8lf %.8lf\n", x, y);

    return 0;
}